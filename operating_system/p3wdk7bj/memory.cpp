#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <deque>

using namespace std;

vector<int> address;
vector<int> pageNum;
deque<int> LruStack;
deque<int>::iterator it;
int replace;
int pageFault;
bool inTlb;
bool tlbFull;
int tIndex;
int tlbHit;
double tlbHitRatio;

struct tlbEntry{
	bool filled;
	int page;
	int frame;
};

struct pageTableEntry{
	bool inPAS;
	int frame;
};

struct PASEntry{
	bool filled;
	int page;
	char bin[256];	
};

void printTlbMiss(int pageNum){
	cout<<"TLB MISS: page "<<pageNum<<" is not in the TLB"<<endl;
}

void printTlbHit(int pageNum, int frameNum, int index){
	cout<<"TLB HIT: page "<<pageNum<<" is contained in frame "<<frameNum<<", found in TLB entry "<<index<<endl<<endl;
}	

void printPasFound(int pageNum, int frameNum){
	cout<<"FOUND: page "<<pageNum<<" is contained in frame "<<frameNum<<endl;
}

void printLoadTlb(int frameNum, int pageNum, int index){
	cout<<"TLB LOAD: frame "<<frameNum<<" containing page "<<pageNum<<" is stored in TLB entry "<<index<<endl<<endl;
}

void printPageFault(int address, int pageNum){
	cout<<"PAGE FAULT: virtual address "<<address<<" contained in page "<<pageNum<<" caused a page fault!!"<<endl;
}

void printLoad(int pageNum, int frameNum){
	cout<<"LOADED: page "<<pageNum<<" is loaded into frame "<<frameNum<<endl;;
}

void insertValue(int index, int value){
	LruStack.erase(it+index);
	LruStack.insert(it+index, value);
}

//copy from BACKING_STORE.bin to the frame
void copyBin(int pageNum, char* bin){
	int num;
	num=256*pageNum;	//offset
	streampos size;
	char* memblock;
	ifstream binFile;
	binFile.open("BACKING_STORE.bin", ios::in|ios::binary);
	if(binFile.is_open()){
		memblock=new char [256];
		bin=memblock;
		binFile.seekg(num, ios::beg);
		binFile.read(memblock, size);
	}else cout<<"ERROR: Can't open BACKING_STORE.bin file"<<endl;
}

int main(){
/*
* open file 'address.txt' and if it is opened,
* get a line from the address.txt file and convert the string value to int
* push back converted int value to the vector 'address'
* close the file when done
* print error message if can't open the file
*/
string line;
int tempAddr;
ifstream addressFile;
addressFile.open("address.txt");
if(addressFile.is_open()){
	while(getline(addressFile, line)){
		tempAddr = stoi(line);
		address.push_back(tempAddr);
		//cout<<tempAddr<<endl; //test print addresses
	}//end of while
	addressFile.close();
}//end of if	
else cout<<"ERROR: Can't open address.txt"<<endl;


/*
* get the page number from the address
* page # = address / 256
*/
for(int i=0;i<address.size();i++){
	pageNum.push_back(address[i]/256);
	//cout<<pageNum[i]<<endl;	//test print page numbers
}//end of for

//================================================================


//declare structs
tlbEntry tlb[4];
pageTableEntry pageTable[16];
PASEntry frame[8];

//initialization==================================================
//tlb
inTlb=false;
tlbFull=false;
tIndex=0;
tlbHit=0;
tlbHitRatio=0;

for(int i=0;i<4;i++){
	tlb[i].filled=false;
	tlb[i].page=-1;
	tlb[i].frame=-1;
}

//page table
for(int i=0;i<16;i++){
	pageTable[i].inPAS = false;
	pageTable[i].frame=-1;
}

//frame
for(int i=0;i<8;i++){
	frame[i].filled = false;
	frame[i].page = -1;
	for(int k=0;k<256;k++)
		frame[i].bin[k]=-1;
}

pageFault=0;

int index;
int page_num;
int pIndex;

/*
* prints
*/

cout << "P = 256 byte (page size)"<<endl;
cout << "VAS = 16 pages" << endl;
cout << "PAS = 8 frames" <<endl;
cout << "TLB = 4 entries" <<endl<<endl;

cout << "RS: ";
for(int i=0;i<address.size()-1;i++)
	cout<<address[i]<<" ,";

cout<<address[address.size()-1]<<endl<<endl;


//================================================================
for(index=0;index<address.size();index++){//big for
	page_num = pageNum[index];
it=LruStack.begin();
replace=-1;

/*
* TLB
* if not full use first fit, if full use FIFO 
* if there is empty splot, first fit
* update tlb below at frame
*/
tIndex=tIndex%4;
//for(int i=0;i<4;i++)
//	cout<<"tlb "<<i<<" "<<tlb[i].page<<endl;

inTlb=false;
//cout<<"tindex "<<tIndex<<endl;
//if page # in TLB, TLB HIT (inTlb=ture)
/*
int q=0;
for(int i=0;i<4;i++){
	if(tlb[i].page==page_num)
		q++;
}
if(q==1)
	inTlb=true;
*/
for(int i=0;i<4;i++){
	if(tlb[i].page==page_num)
		inTlb=true;
}

//cout<<"intlb "<<inTlb<<endl;
int p=0;
for(int i=0;i<4;i++){
	if(tlb[i].page==page_num){
		p=i;
	}
}
if(inTlb){
	printTlbHit(page_num,tlb[p].frame, p);
	tlbHit++;	
}
else{
	printTlbMiss(page_num);
}

bool inFrame=false;
if(!inTlb){
/*
* page table contains bool inPAS and int frame
* inPAS checks if the page number is in the frame
* frame provides which frame the page number is stored
* page_num is the index of the page table (pIndex)
* either TLB hit or miss, page number can be in the frame
*/
	//check if page_num is in the frame
	pIndex = page_num;
	//bool inFrame = false;
	if(pageTable[pIndex].inPAS == true){
		//no page fault
		//can be TLB HIT or MISS
		inFrame=true;
		if(inTlb==false&&inFrame)//not in tlb but in frame
		printPasFound(page_num, pageTable[pIndex].frame);
		//inFrame=true;
	}//end of if
	else if(pageTable[pIndex].inPAS ==false){
		pageFault++;
		//TLB MISS
		//print page fault
		printPageFault(address[index], page_num);
		//load to PAS
		//load to TLB
	}//end of else if

}
//=========================================================================
//stack working
/*
* LRU stack implementation
*/

int sIndex=0;
bool inStack=false;
//cout<<LruStack.size()<<endl;
if(!LruStack.empty()){
for(int i=0;i<LruStack.size();i++){
	if(LruStack.at(i)==page_num){
		inStack=true;
		sIndex=i;
	}
}//end of for
}//end of if


//cout<<"instack "<<inStack<<endl;
//cout<<"sIndex "<<sIndex<<endl;
//cout<<"size "<<LruStack.size()<<endl;

if(inStack){
	if(LruStack.size()<8){
		if(sIndex==0){
			LruStack.pop_front();
			LruStack.push_back(page_num);
		}
		else{
		//cout<<LruStack.at(sIndex)<<endl;
		int t=LruStack.at(sIndex);
		for(int i=sIndex;i<LruStack.size()-1;i++){
			//cout<<LruStack.at(LruStack.size()-1)<<endl;
			insertValue(i, LruStack.at(i+1));
			//cout<<LruStack.at(i)<<endl;
		}//end of for
			LruStack.pop_back();
			LruStack.insert(it+LruStack.size(), t);
		}
	}//end of if //replace = LruStack.at(sIndex);
	else if(LruStack.size()==8){
			int t=LruStack.at(sIndex);
			LruStack.erase(it+sIndex);
			LruStack.push_back(t);
	}//end of else if
}
else if(!inStack){
	if(LruStack.empty()){
		LruStack.push_back(page_num);
	}
	else if(LruStack.size()==8){
		replace = LruStack.at(0);//replace
		LruStack.pop_front();//page # to replace
		LruStack.push_back(page_num);
	}//end of if
	else if(LruStack.size()<8){
		//insertValue(LruStack.size()-1, page_num);
		//LruStack.insert(it+LruStack.size()-1, page_num);
		LruStack.push_back(page_num);
	}//end of else if
}//end of else if
//}//end of if	
//===========================================================================



//to check stack values durine process
//for(int i=0;i<LruStack.size();i++)
//  cout<<"index "<<i<<" "<<LruStack.at(i)<<endl;
//cout<<endl;


//to check to page # to be replaced
//cout<<"replace " <<replace<<endl;


//============================================================================
//frame working
/*
* frame implementation
*/
if(!inTlb){
//if frameCount==8, frame is full
//if framecount <8, frame is not full
int frameCount=0;
for(int i=0;i<8;i++){
	if(frame[i].filled==true)
		frameCount++;
}//end of for

for(int i=0;i<8;i++){
	if(frame[i].page==page_num){
        inFrame=true;
		break;
	}
}//end of for

bool frameFull=false;
if(frameCount==8)
	frameFull=true;

if(!inFrame){//page not in the frame tlb miss
	if(frameCount<8){//frame not full use first fit to fill it
		for(int i=0;i<8;i++){
			if(frame[i].filled==false){//frame not full and not filled
				//update frame and copy from bin file
				printLoad(page_num, i);
				copyBin(page_num, frame[i].bin);
				frame[i].page=page_num;
				frame[i].filled=true;
				//update page table
				pageTable[page_num].inPAS=true;
				pageTable[page_num].frame=i;
				//update TLB
				tlb[tIndex].filled=true;
				tlb[tIndex].page=page_num;
				tlb[tIndex].frame=i;
				printLoadTlb(i, page_num, tIndex);
				//cout<<"frame "<<i<<" " <<frame[i].page<<endl;
				break;//found empty spot. get out of for loop
			}
		}//end of for
	}//end of if
	else if(frameCount==8){//frame is full. Use LRU stack algorithm to replace page #
		for(int i=0;i<8;i++){
			if(frame[i].page==replace){
				//update frame with page #
				printLoad(page_num, i);
				copyBin(page_num,frame[i].bin);
				frame[i].page=page_num;
				//update page table
				pageTable[page_num].frame=i;
				pageTable[page_num].inPAS=true;
				//update TLB
                tlb[tIndex].filled=true;
                tlb[tIndex].page=page_num;
                tlb[tIndex].frame=i;
				printLoadTlb(i, page_num, tIndex);
				//cout<<"frame "<<i<<" " <<frame[i].page<<endl;
				break;
			}//end of if
		}//end of for
	}//end of ele if
	//if replace !=-1, page # in frame is replaced
	//and no longer in the frame
	
	if(replace!=-1){//need to update frame and page table
		pageTable[replace].inPAS=false;
	}//end of if
}//end of if
else if(inFrame){//page # in the frame
	if(inTlb==false){//tlb miss but page # in frame update tlb and print
		int k=0;
		for(int i=0;i<8;i++){
			if(frame[i].page==page_num){
				k=i;
			}
		}
		printLoadTlb(k,page_num,tIndex); 
	}//end of if
}//end of else if
//=========================================================================

//only increment tlb index if page # not in the frame(tlb miss)
if(inTlb==false)
tIndex++;
//cout<<"replace "<<replace<<endl;
//=============================================
}//end of if(!inTlb)
}//end of big for

//check if stack has the right value
//for(int i=0;i<LruStack.size();i++)
//	cout<<LruStack.at(i)<<endl;

//confirm that stack is 8 after all process is done
//cout <<"size "<<LruStack.size()<<endl;


//confirm page # is in right frame
//for(int i=0;i<8;i++){
//	cout<<"frame "<<i<<" " <<frame[i].page<<endl;
//}


/*
*print result
*/
//TLB Hit Ratio
tlbHitRatio=(double)tlbHit/address.size();
//total num of address
cout<<endl<<"Total address references: "<< address.size()<<endl;

//number of TLB hit
cout<< "TLB Hits: " <<tlbHit<<endl;
//TLB hit ratio-> TLB hit / address.size()
cout<< "TLB Hit Ratio: " <<tlbHitRatio<<endl;
//number of page fault
cout<<"Page Faults: "<<pageFault<<endl<<endl;

//check pageTable
cout<<"The contents of the page table after simulation:"<<endl;
for(int i=0;i<16;i++){
	if(pageTable[i].inPAS==true){
		cout<<"page "<<i<<" in frame "<<pageTable[i].frame<<endl;
	}//end of if
	else if(pageTable[i].inPAS==false){
		cout<<"page "<<i<<" not in physical memory"<<endl;
	}//end of else if
}//

cout<<endl;
//check frame
cout<<"The contents of each frame:"<<endl;
for(int i=0;i<8;i++){
	cout<<"frame "<<i<<" contains page "<<frame[i].page<<endl;
}

	return 0;
}//end of main