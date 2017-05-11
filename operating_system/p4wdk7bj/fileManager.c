#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>	//to use isalpha

#include "disk.h"

//struct for OFT, i.e. file descriptors
struct oftEntry{
	char status;
	int offset;
	int index;
};

//first block of 64 blocks virtual disk
struct superBlock{//16 bytes
	char dir[4];
	char fat[4];
	char unused[4];
	char dataBlock[4];
};

//entry for a block of directory
//dir: block 1 ~ 8 of 64 blocks virtual disk
struct DirEntry{//16 bytes
	char status;
	char firstBlock[2];
	char fileName[4];
	char fileLen[3];
	char unused[6];
};

//one of 4 entries of FAT block
//FAT: block 9 ~ 16
struct FATEntry{//16 bytes
	char status;
	char blockNum[3];
};

//data block 32 ~ 63
struct DataEntry{
	char data[16];
};

//to find blocks that will be used
int usedBlock[32];

//global
struct superBlock s_block;
struct DirEntry dir[8];
struct oftEntry oft[4];
struct DataEntry data[64];//64 to make it easier to use index
						  //will use 32 ~ 63 only
struct FATEntry fat[64];  //will use 32 ~ 63 only


//================customized function=============================================
int charToInt(char c1, char c2){
	int i = c1-'0';
	int j= c2-'0';
	int t = i*10+j;
	return t;
}

int char3ToInt(char c1, char c2, char c3){
	int i = c1-'0';
	int j = c2-'0';
	int k = c3-'0';
	int t = i*100+j*10+k;
	return t;
}

int compareStrings(char* s1,char* s2){ //Returns 0 if equal
	int length = strlen(s1);
	int length2 = strlen(s2);
	int length3 = 0;
	if (length2 > length) length3 = length2;
	else length3 = length;

	for (int i = 0; i < length3; i++){
		if (i >= length){
			if (isalpha(s2[i]))
				return -1;
			else
				break;
		}
		else if (i >= length2){
			if (isalpha(s1[i]))
				return -1;
			else
				break;
		}
		if (s1[i] != s2[i] && isalpha(s1[i]) && isalpha(s2[i]))
			return -1;
	}
	return 0;
}

void printSuperBlock(){
	printf("%s %c%C%C%C\n", "super block dir ", s_block.dir[0], 
												s_block.dir[1], 
												s_block.dir[2], 
												s_block.dir[3]);
	printf("%s %c%C%C%C\n", "super block fat ", s_block.fat[0],
												s_block.fat[1],
												s_block.fat[2],
												s_block.fat[3]);
	printf("%s %c%C%C%C\n", "super block unused ", s_block.unused[0],
												   s_block.unused[1],
												   s_block.unused[2],
												   s_block.unused[3]);

	printf("%s %c%C%C%C\n", "super block data block ", s_block.dataBlock[0],
													   s_block.dataBlock[1],
													   s_block.dataBlock[2],
													   s_block.dataBlock[3]);
}

void printOft(){
 	for(int i=0; i<4;i++){
		printf("%s%d%s\n", "OFT[",i,"]");
        printf("%s%c %s%d %s%d\n", "status ",oft[i].status, "offset ",oft[i].offset, "index ",oft[i].index);
    }
}

void printDir(){
	for(int i=0;i<8;i++){
		printf("%s%d%s\n", "dir[",i,"]");
		printf("%s %c\n", "status ", dir[i].status);
		printf("%s %c%c\n", "first block ", dir[i].firstBlock[0], dir[i].firstBlock[1]);
		printf("%s %c%c%c%c\n", "file name ", dir[i].fileName[0] ,
										      dir[i].fileName[1] ,
											  dir[i].fileName[2] ,
											  dir[i].fileName[3]);
		printf("%s %c%c%c\n", "file length ", dir[i].fileLen[0], dir[i].fileLen[1], dir[i].fileLen[2]);
		printf("%s %c%c%c%c%c%c\n\n", "unsued ", dir[i].unused[0] ,
											   dir[i].unused[1] ,
											   dir[i].unused[2] ,
											   dir[i].unused[3] ,
											   dir[i].unused[4] ,
											   dir[i].unused[5]);
	}
}

void printFat(){
	for(int i=32;i<64;i++){
		printf("%s%d%s\n", "FAT[",i,"]");
		printf("%s %c\n", "FAT status ", fat[i].status);
		printf("%s %C%C%C\n", "FAT next block number ", fat[i].blockNum[0],
														fat[i].blockNum[1],
														fat[i].blockNum[2]);
	}
}

void printData(){
    for(int i=32;i<64;i++){
        printf("%s%d%s\n", "Data Block[",i,"]");
        printf("%s %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", "Data in data block ", data[i].data[0],
                                                       data[i].data[1],
                                                       data[i].data[2],
													   data[i].data[3],
                                                       data[i].data[4],
                                                       data[i].data[5],
                                                       data[i].data[6],
                                                       data[i].data[7],
                                                       data[i].data[8],
                                                       data[i].data[9],
                                                       data[i].data[10],
                                                       data[i].data[11],
                                                       data[i].data[12],
                                                       data[i].data[13],
                                                       data[i].data[14],
                                                       data[i].data[15]);
    }
}

void printBlockData(int nbyte, int fb){
		int firstBlock = fb;
        printf("%s%d%s\n", "Data Block[",firstBlock,"]");
        printf("%s %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", "Data in data block ", data[firstBlock].data[0],
                                                       data[firstBlock].data[1],
                                                       data[firstBlock].data[2],
                                                       data[firstBlock].data[3],
                                                       data[firstBlock].data[4],
                                                       data[firstBlock].data[5],
                                                       data[firstBlock].data[6],
                                                       data[firstBlock].data[7],
                                                       data[firstBlock].data[8],
                                                       data[firstBlock].data[9],
                                                       data[firstBlock].data[10],
                                                       data[firstBlock].data[11],
                                                       data[firstBlock].data[12],
                                                       data[firstBlock].data[13],
                                                       data[firstBlock].data[14],
                                                       data[firstBlock].data[15]);
    
}
//=================================================================================

//make_fs is working
int make_fs(char *disk_name){
	//check if the name of the disk has more than 4 characters
	size_t length=strlen(disk_name);		
	if(length > 4){
		//printf("%d\n", length); //test print
		fprintf(stderr, "Invalid disk name: more than 4 characters\n");
		return -1;
	}

	//check if disk name is only alphabetic
	char *c=disk_name;
	//printf("%s\n", c);	//test print
	for(int i=0; i<4;i++){
		if(isalpha(c[i])==0){//non alphabet char found
			//fprintf(stderr, "Invalid disk name: invalid character\n");
			return -1;
		}//end of if
	}//end of for

	void* tmp = malloc(16);
	tmp="0108091617313263";
	
	void* tmp2=malloc(16);
	tmp2="0000000000000000";	
	//make disk, open it, and initialize each block
	//block 0 ~ 63
	if(make_disk(disk_name)==0){
		open_disk(disk_name);
		//initialize super block to the disk
		block_write(0, tmp);
		//block 1 ~ 63 initialize to 0 and write to the disk
		for(int i=1; i<64;i++){
			block_write(i, tmp2);
		}
		close_disk(disk_name);				
	}//end of if
	else//can't make disk
		return -1;	

	return 0;
}
//=================================================================

//mount_fs is working
int mount_fs(char *disk_name){

	//initialize OFT
	for(int i=0;i<4;i++){
		oft[i].status='0';
		oft[i].offset=0;//offset is int
		oft[i].index=0;//index is int
	}
	//printOft(); //test print
	

	//buffer to read 16 bytes (1 block)
	char* tmp=malloc(16);

	open_disk(disk_name);
	
	//read block 0 from the disk and write to the buffer tmp
	block_read(0,tmp);
	
	//initialize super block s_block
	for(int i=0;i<4;i++){//dir
		s_block.dir[i]=tmp[i];
	}
	for(int i=4;i<8;i++){//fat
		s_block.fat[i-4]=tmp[i];
		//printf("%c\n", s_block.fat[i]);
	}
	for(int i=8;i<12;i++){//unused
		s_block.unused[i-8]=tmp[i];
	}
	for(int i=12;i<16;i++){//data block
		s_block.dataBlock[i-12]=tmp[i];
	}
	//printSuperBlock(); //test print

	//initialize directory block 1 ~ 8
	int i=0;
	for(i=1;i<9;i++){
		block_read(i, tmp);//read block 1 ~ 8
		//printf("%s\n", tmp);	//test print
		dir[i-1].status=tmp[0];
		for(int j=1;j<3;j++){
			dir[i-1].firstBlock[j-1]=tmp[j];
		}			
		for(int j=3;j<7;j++){
			dir[i-1].fileName[j-3]=tmp[j];
		}
		for(int j=7;j<10;j++){
			dir[i-1].fileLen[j-7]=tmp[j];
		}
		for(int j=10;j<16;j++){
			dir[i-1].unused[j-10]=tmp[j];
		}
	}
	//printDir(); //test print

	int start=32;
	for(int i=0;i<8;i++){
		block_read(i+9, tmp);//read block 9 ~ 16. each block is 16 bytes
		//printf("Block read = %s\n",tmp); //test print
		fat[start].status=tmp[0];
		fat[start].blockNum[0]=tmp[1];
		fat[start].blockNum[1]=tmp[2];
		fat[start].blockNum[2]=tmp[3];
		start++;			

    	fat[start].status=tmp[4];
	    fat[start].blockNum[0]=tmp[5];
    	fat[start].blockNum[1]=tmp[6];
       	fat[start].blockNum[2]=tmp[7];	   	 
		start++;

    	fat[start].status=tmp[8];
       	fat[start].blockNum[0]=tmp[9];
        fat[start].blockNum[1]=tmp[10];
   	    fat[start].blockNum[2]=tmp[11];	    
		start++;

   	    fat[start].status=tmp[12];
       	fat[start].blockNum[0]=tmp[13];
        fat[start].blockNum[1]=tmp[14];
   	    fat[start].blockNum[2]=tmp[15];    	
		start++; 
	}
	//printFat(); //test print

	//initialize data block 32 ~ 63		
	for(int i=32; i<64;i++){
		block_read(i, tmp);//read block 9 ~ 16. each block is 16 bytes
		for(int j=0;j<16;j++){
			data[i].data[j]=tmp[j];//char type
		}
	}
	//printData();	//test print

//	close_disk(disk_name);	//why?
	//printf("%s\n", &s_block.dir);
	return 0;
}

int lenOfFile=0;	//for future use since dir.filename is printing 0s
//fs_create working
int fs_create(char *name){
	//First, check length of file name
	if (strlen(name)>4){
		printf("%s\n", "File name too long");
		return -1;
	}

	//Check how many files are in dir
	int filecount = 0;
	for (int i = 1; i < 9; i++){
		if (dir[i-1].status == '1'){
			filecount++;
			if (filecount >= 8){
				//printf("Max # Files Already Exist.\n");
				return -1;
			}
			if (compareStrings(dir[i-1].fileName, name) == 0){
				//printf("File of name %s already exists.\n",name);
				return -1;
			}
		}
	}

	lenOfFile=strlen(name);
	//find the first emtpy block and store in the first dir.firstBlock
	for (int i = 1; i < 9; i++){
//		printf("i = %d\n", i);
		if (dir[i-1].status == '0'){
			for (int j = 32; j < 64; j++){//fat[32] ~ fat[63]
				//printf("  j=%d\n",j);
				//printf("  fat[%d]=%d\n",j,fat[j].status);
				//printf("  %d\n", '0'==fat[j].status);	
				int val = (fat[j].status == '0');//if fat[j] is empty, return 1
				//printf("val=%d\n",val);
				if (val == 1){
					//printf("Hello\n");
					//printf("fat status[%d]=%c\n",0,fat[j].status);
					//dir firstblock: 2 bytes; fat blockNum: 3 bytes
					//store block number at fat blockNum index 1 and 2
		
					//to convert int to char
					char *tmp = malloc(2);
					sprintf(tmp, "%d", j);
					//printf("%c%c\n", tmp[0], tmp[1]); //test print
					dir[i-1].firstBlock[0] = tmp[0];
					dir[i-1].firstBlock[1] = tmp[1];
					dir[i-1].fileLen[0] = '0';
					dir[i-1].fileLen[1] = '0';
					dir[i-1].fileLen[2] = '0';
					
					//fat[j].status = '1';
					//printf("%s %c%c\n", "dir first block ", dir[i-1].firstBlock[0], dir[i-1].firstBlock[1]);//test
					break;
				}
			}
	
		//update dir status
		dir[i-1].status='1';
	
		//store file name to the dir.fileName
		dir[i-1].status= '1';//now dir[i-1] is filled
		int diff = 4 - strlen(name);//the len of the file name can be 1 ~ 4
		//printf("%s%d\n", "len name ", diff);
		for(int j=0;j<diff;j++){ //since we are storing from index 0 upto the length of the name
			dir[i-1].fileName[j]=name[j];
		}

		//dir[i-1].fileLen[0]=7;//dir[i-1].fileName printing entire bytes
		//int l=strlen(dir[i-1].fileName);//
		//printf("%s%d\n", "len ", l);
		//printf("filename is %s\n", dir[i-1].fileName);//why is it printing so many 0s?
		//printf("name is %s\n", name);	
			break;
		}
	}
	
	return 0;
}

//fs_open working
int fs_open(char *name){
	int numfds = 0;//count number of file descriptors
	for (int i = 0; i < 4; i++){
		if (oft[i].status == '1'){
			numfds++;
			//cannot open same file more than once at the same time
			//i.e. file already exist
			int index=oft[i].index;	//oft[i].index is int value
			//printf("index is %d\nfilename is %s\n, name is %s\n", 
				//oft[i].index, dir[index].fileName, name);
			if (compareStrings(dir[index].fileName,name) == 0){
				//printf("Cannot open same file twice\n");
				return -1;
			}
		}
	}

    //can't have more than 4 fds
    if (numfds >=4){
        //printf("Four files already open. Cannot open another.\n");
        return -1;
    }
	
	//fs_create will store the file name to one of the directories
	//first check which dir has it (find the index of dir)
	//assign it to oft.index (first fit)
	//assign fd from oft
	for(int i=0;i<8;i++){
		if(dir[i].status == '1' && compareStrings(name, dir[i].fileName)==0){
			for(int j=0;j<4;j++){
				if(oft[j].status=='0'){
					oft[j].index = i;
					oft[j].status='1';
					oft[j].offset= 0;
					return j;//the value j is the fd
				}
			}//end of for
		}//end of if
	}//end of for

	//Only remaining possibility is file not in directory
	//printf("File does not exist in directory\n");
	return -1;
}


//working
int fs_get_filesize(int fildes){
	int i1= (dir[oft[fildes].index].fileLen[0]-'0');
	int i2= (dir[oft[fildes].index].fileLen[1]-'0');
	int i3= (dir[oft[fildes].index].fileLen[2]-'0');
	int size=i1*100+i2*10+i3;
	return size;
}


//have to write back to the disk (mydk) when fs_close is called
//need more thing to do 
int fs_close(int fildes){
/*
1. close fd. if fd does not exist or is not open, return -1
2. update oft
*/
	//oft status is '1' when opened`
	if(oft[fildes].status=='0')//fd not open can't close
		return -1;
	
	//fd value invalid
	if(fildes<0 || fildes > 4)
		return -1;

	//reset oft
	oft[fildes].status='0';
//	oft[fildes].offset=0;//offset is int
//	oft[fildes].index=0;//index is int
	//printOft();

	return 0;
}

//have to do this later again. not done yet
int fs_delete(char *name){
/*
delete the file with name 'name' from the dir and free all data blocks and meta data that corresponds to that file
1. file being deleted must not be opened: cannot be any open fd that refers to the file name. return -1
2. if file name does not exist, return -1;
*/
	//check if file is in the dir
	int index=0;
	for(int i=0;i<8;i++){
		 if(compareStrings(name, dir[i].fileName)==0){
			index=i;//the file is in dir[index]
			break;
		}	
	}
	//printf("index = %d\n", index);
	//printOft();
	//check if the file is open
	for(int i=0;i<4;i++){
		if(oft[i].index==index){
			return -1; //can't delete open file
		}
	}
	//file is open
	//printf("oft[oftindex].status=%c\n", oft[oftIndex].status);
	//printf("%c\n", oft[1].status);	
//======================================================

	//printFat();	
			//1. reset dir
			//2. reset fat
			//dir[i].status='0';
		//	printf("index %d\n", index);
			char c1= dir[index].firstBlock[0];
			char c2= dir[index].firstBlock[1];
			int block = charToInt(c1, c2);
			int eof=1;//until end of the file
			//reset fat table
			while(eof){
			//	printf("block %d\n", block);
				int next= charToInt(fat[block].blockNum[1], fat[block].blockNum[2]);
			//	printf("next %d\n", next);
				int end= (fat[block].blockNum[0]=='e'&& fat[block].blockNum[1]=='o'&& fat[block].blockNum[2]=='f');
			//	printf("end %d\n", end);
                fat[block].status='0';  
                fat[block].blockNum[0]='0';
                fat[block].blockNum[1]='0';
                fat[block].blockNum[2]='0';
				//reset is done
				if(end)
					eof=0;
				
				//printf("bloc %d\n", block);
				//reset not done
				block=next;				
			//	printf("last block %d\n", block);
			//	break;
			}
	dir[index].status = '0';
	
//========================================================		
/*
		else
			//oft[i].status=='1' -> fd is open, can't delete and
			//file name does not exist
			for(int i=0; i<8;i++){
				if(compareStrings(name, dir[i].fileName)==0){//file in the dir
					
				}
			
			return -1;
*/
		
	return 0;
}

//int fs_read(int fildes, void *buf, size_t nbyte){
//	int readBytes=0;
//	
//	//convert void* buf to char buf
//	//char* cbuf = (char*)buf;
//
//	//validate fildes
//	if(fildes<0 || fildes>4)//fildes can be 0, 1, 2, 3
//		return -1;
//	
//	//can't read file that is not opened
//	if(oft[fildes].status == '0')
//		return -1;
//	
//	//can't read empty file
//	int fd= fs_get_filesize(fildes);
//	if(fd==0)
//		return -1;
//
//	//if the file size is less then nbyte
//	if(fd<=nbyte){
//		nbyte=fd;
//		readBytes=nbyte;//can only read nbyte
//	}
//	
//	//first block
//	int dirindex=oft[fildes].index;
//	int firstBlock= charToInt(dir[dirindex].firstBlock[0], dir[dirindex].firstBlock[1]);
//	//printf("first block %d\n", firstBlock);	
//
//	
//	//after fs_write, offset will point to the location next to the last byte written
//	//printf("offset %d\n", oft[fildes].offset);
//	int offset = (oft[fildes].offset);//subtract one because it is pointing one byte right to the last byte written
//	//printf("offset= %d\n", offset);
//	int ptr=offset%16;
//	int temp=offset/16;
//	if(offset%16!=0)
//		offset=temp+1;
//	else
//		offset=temp;	//now we know which block the offset is pointing
//	
//	int currBlock= firstBlock+offset;
//	char c1= fat[currBlock].blockNum[0];	
//	char c2= fat[currBlock].blockNum[1];	
//	char c3= fat[currBlock].blockNum[2];	
//	//printf("block location %d\n", firstBlock+offset);
//	//printf("%c%c%c\n", c1, c2, c3);
//	//if ptr is point the last block, return 0
//	if(c1=='e'&& c2=='o' && c3=='f'	)
//		return 0;
//
//	//the location of the ptr at current block
//	int currPtr= ptr-1;//need to subtract one because this will be used as index
//	
//	int needBlock=0;
//	for(int i=0;i<32;i++){
//		if(usedBlock[i]!=0)
//			needBlock++;//total block needed to write buffer
//	}
//	int in=0;
//	for(int i=0;i<32;i++){
//		if(usedBlock[i]==currBlock)
//			in=i;//index of current block
//	}
//	
//
//	char* tmp=malloc(nbyte);
//	int boo=0;
//	int cin=0;
//	int count=nbyte;
////	printf("offset %d\n", offset);
////	printf("curr ptr %d\n", currPtr);
//	int q= currPtr+nbyte;
//	while(1){
//		if(count==0)
//			break;
//		if(boo==1)
//			currPtr=0;
//		for(int i=currPtr;i<q;i++){
//			tmp[cin]=data[usedBlock[in]].data[i];		
//			//printf("%c", tmp[cin]);
//			cin++;
//			count--;
//			oft[fildes].offset++;
//		}
//			
//		if(q>16)
//			q-=16;
//		boo=1;
//		if(in!=needBlock)
//			in++;
//		else
//			break;
//		
//	}//end of while
//	//buf= (void*)tmp;
//
//	return nbyte;
//}


int fs_read(int fildes, void *buf, size_t nbyte){
	int readBytes = 0; // Num bytes actually read
	//OFT entry contains char status, int index, int offset
	//DIR entry contains char status; char firstBlock[2]; char fileName[4]; char fileLen[3];
	//FAT entry contains char status; char blockNum[3];

	//Convert void* buf to char buf
	char* cbuf = (char*)buf;
	
	//Don't want array out of bounds issue
	if (fildes < 0 || fildes > 4)
		return -1;
	//Don't want to look at file that's not open
	if (oft[fildes].status == '0')
		return -1;	

	int dirindex = oft[fildes].index;

	
	int filelen = char3ToInt(dir[dirindex].fileLen[0],dir[dirindex].fileLen[1],dir[dirindex].fileLen[2]);	
	if (filelen == 0)
		return 0; //Can't read empty file
	
	int fd= fs_get_filesize(fildes);
	//printf("file size %d\n", fd);
	if(fd==0)
		return 0; //can't read empty file

	//Don't know why this would occur, but in case
	if (dir[dirindex].status == '0')
		return -1;	
	
	//Extract file length in int value
	//int filelen = char3ToInt(dir[dirindex].fileLen[0],dir[dirindex].fileLen[1],dir[dirindex].fileLen[2]);

	//Current Block	
	int currBlock = charToInt(dir[dirindex].firstBlock[0],dir[dirindex].firstBlock[1]);
	//Once at correct block, read and update offset
	//function assumes buf large enough to hold at least nbyte bytes
	int eof = 0; //End of File starts as false
	int bufindex = 0; //index of where to put in buffer
	int blocknum = oft[fildes].offset/16; //Where to store block_read results

	//Advance currBlock by offset as stored in OFT
	for (int i = 0; i < blocknum; i++){
			currBlock = char3ToInt(fat[currBlock].blockNum[0] ,
									fat[currBlock].blockNum[1],
									fat[currBlock].blockNum[2] );
	}
	
	int blockOffset = oft[fildes].offset%16-1;
	if (blockOffset < 0)
		blockOffset = 0;
	while(readBytes < nbyte && eof < 3){
		//block_read(currBlock, readHere);
//		for (int i = 0; i < 16; i++){
//			if (blockOffset > 0){
//				i += blockOffset;
//				blockOffset = 0;
//			}
			char curchar = data[currBlock].data[blockOffset];
			//Keep checking for EOF to see when to stop reading
			if (curchar == 'e' || curchar == 'E' ||
				curchar == 'o' || curchar == 'O' ||
				curchar == 'f' || curchar == 'F'   ) {
					eof++;
			} else if (eof > 0){
				eof = 0;
			}
			//Stop reading if eof happens, return the buffer
			if (eof == 3){
				cbuf[bufindex-2] = '0';
				cbuf[bufindex-1] = '0';
				readBytes--; readBytes--;
				bufindex -= 2;
				oft[fildes].offset += readBytes;
				break;
			} else {
				cbuf[bufindex] = data[currBlock].data[blockOffset];
				if ((blockOffset+1)%16 == 0){
					blockOffset = (blockOffset+1)%16;
					currBlock = char3ToInt(fat[currBlock].blockNum[0] ,
											fat[currBlock].blockNum[1],
											fat[currBlock].blockNum[2] );
				}
				else
					blockOffset++;
				bufindex++;
				readBytes++;
			}
		}
		//sscanf(fat[currBlock].blockNum, "%d", &currBlock);
//		currBlock = char3ToInt(fat[currBlock].blockNum[0] ,
//								fat[currBlock].blockNum[1],
//								fat[currBlock].blockNum[2] );
		

	return readBytes;
}


//fs_write working
int fs_write(int fildes, void *buf, size_t nbyte){
	//int writeBytes= 0;
	
	//valid fildes is 0, 1, 2, 3
	if(fildes<0 || fildes>4)
		return -1;

	//max allowalbe byte is 512
	if(nbyte > 512)
		nbyte = 512;
	
	//no space to write, return 0
	if(fat[63].status=='1')
		return 0;
	
	//not enough space to write entire bytes
	int emptyBlock=0;
	for(int i=32;i<64;i++){
		if(fat[i].status=='0')
			emptyBlock++;
	}	
	int emptyByte= emptyBlock*16;
	if(emptyByte < nbyte)
		nbyte= emptyByte;
	
	//find total number of blocks needed
	int t1= nbyte/16;
	int t2= 0;
	if(nbyte%16 !=0)
		t2=1;
	int needBlock=t1 + t2;
	
	//convert void* buf to char* cbuf
	char* cbuf = (char*)buf;

	//first, need to find empty block. check fat[i].status
	//if fat[i].status is 0, set to 1
	//write 16 bytes
	//repeat
	//fat[i].blockNum[3] should store next block info
	//if last block, fat[last].blockNum =='eof'
	
	//find blocks that will be used
	//first initialize array to 0
	//int usedBlock[32]; //declared as global so that read can use this data
	for(int i=0;i<32;i++)
		usedBlock[i]=0;
	
	//we know number of need blocks
	for(int i=0;i<needBlock;i++){
		int j;
		for(j=32;j<64;j++){
			if(fat[j].status=='0')
				break;
		}//end of for
		fat[j].status='1';
		usedBlock[i]=j;
	}//end of for

/* test print
	for(int i=0;i<needBlock;i++){
		printf("block need: %d\n", usedBlock[i]);
	}
*/
	//update fat table
	//fat block stores the next block
	if(needBlock==1){
		fat[usedBlock[0]].blockNum[0]='e';
		fat[usedBlock[0]].blockNum[1]='o';
		fat[usedBlock[0]].blockNum[2]='f';
	}else{
		for(int i=0;i<needBlock-1;i++){
			char c1= usedBlock[i+1]/10 + '0';
			char c2= usedBlock[i+1]%10 + '0';
			fat[usedBlock[i]].blockNum[0]= '0';
			fat[usedBlock[i]].blockNum[1]= c1;
			fat[usedBlock[i]].blockNum[2]= c2;
		}
	}//end of else
	//last block of fat table is 'eof'	
	fat[usedBlock[needBlock-1]].blockNum[0]='e';
	fat[usedBlock[needBlock-1]].blockNum[1]='o';
	fat[usedBlock[needBlock-1]].blockNum[2]='f';
	
	//printFat();	
	//write data to data block
	int dIn=0;
	int writeByte=nbyte;
	for(int i=0;i<needBlock;i++){
		int in=0;
		if(writeByte<=16)
			in=writeByte;
		else if(writeByte>16){
			in=16;
			writeByte-=16;
		}
		for(int j=0;j<in;j++){
			data[usedBlock[i]].data[(j)]= cbuf[dIn];
			dIn++;
		}
	}
	//printData();	

	//update dir file length
	int hundredth;
    int tenth;
    int ones;
    char c1;//hundredth
    char c2;//tenth
    char c3;//ones
    if(nbyte>=100){//if file is greater than or equal to 100 bytes
        hundredth= (nbyte/100);
        tenth= (nbyte-100)/10;
        ones= (nbyte-100)%10;
        //printf("%d%d%d\n", hundredth, tenth, ones);
        c1=hundredth+'0';
        c2=tenth+'0';
        c3=ones+'0';
    }else if(nbyte>=10 && nbyte<100){// 10<= file size <100
        c1='0';
        tenth= nbyte/10;
        ones=(nbyte%10);
        c2=tenth+'0';
        c3=ones+'0';
    }else if(nbyte<10){
        c1='0';
        c2='1';
        ones=nbyte;
        c3=ones+'0';
    }

    dir[oft[fildes].index].fileLen[0]=c1;
    dir[oft[fildes].index].fileLen[1]=c2;
    dir[oft[fildes].index].fileLen[2]=c3;
    //printf("%c%c%c\n", c1, c2, c3);
	
	//update oft offset
	//after fs_write finishes its job, the file pointer will point to the location next to the ast byte written
	oft[fildes].offset=(nbyte+1);

	
	return nbyte;
}

//done
int fs_lseek(int fildes, off_t offset){
// it is an error to set the file pointer out of bounds (i.e. before the beginning of the file or after the end of the file)
//
	//invalid fildes
	if(fildes < 0 || fildes > 4)
		return -1;
	
	int position = oft[fildes].offset;
	//offset*=-1;
	int newpos = position + offset;
	//printf("position %d, offset %d, diff %d\n", oft[fildes].offset, offset, diff);//test print
	if(newpos<0)
		return -1;
	oft[fildes].offset = newpos;

	return 0;
}

//===============================================================================
// DO THIS AT THE END */

int dismount_fs(char *disk_name){
	//Write the directory
	char dirblock[16];
	for (int i = 1; i < 9; i++){
		dirblock[0]  = dir[i-1].status;
		dirblock[1]  = dir[i-1].firstBlock[0];
		dirblock[2]  = dir[i-1].firstBlock[1];
		dirblock[3]  = dir[i-1].fileName[0];
		dirblock[4]  = dir[i-1].fileName[1];
		dirblock[5]  = dir[i-1].fileName[2];
		dirblock[6]  = dir[i-1].fileName[3];
		dirblock[7]  = dir[i-1].fileLen[0];
		dirblock[8]  = dir[i-1].fileLen[1];
		dirblock[9]  = dir[i-1].fileLen[2];
		dirblock[10] = '0';
		dirblock[11] = '0';
		dirblock[12] = '0';
		dirblock[13] = '0';
		dirblock[14] = '0';
		dirblock[15] = '0';
		block_write(i,dirblock);
	}
	//Write the FAT
	char fatblock[16];
	for (int i = 32; i < 64; i+=4){
		fatblock[0]  = fat[i].status;
		fatblock[1]  = fat[i].blockNum[0];
		fatblock[2]  = fat[i].blockNum[1];
		fatblock[3]  = fat[i].blockNum[2];
		fatblock[4]  = fat[i+1].status;
		fatblock[5]  = fat[i+1].blockNum[0];
		fatblock[6]  = fat[i+1].blockNum[1];
		fatblock[7]  = fat[i+1].blockNum[2];
		fatblock[8]  = fat[i+2].status;
		fatblock[9]  = fat[i+2].blockNum[0];
		fatblock[10] = fat[i+2].blockNum[1];
		fatblock[11] = fat[i+2].blockNum[2];
		fatblock[12] = fat[i+3].status;
		fatblock[13] = fat[i+3].blockNum[0];
		fatblock[14] = fat[i+3].blockNum[1];
		fatblock[15] = fat[i+3].blockNum[2];
		block_write(i/4+1,fatblock);
	}
	//Write the data
	char datablock[16];
	for (int i = 32; i < 64; i++){
		datablock[0]  = data[i].data[0] ;
		datablock[1]  = data[i].data[1] ;
		datablock[2]  = data[i].data[2] ;
		datablock[3]  = data[i].data[3] ;
		datablock[4]  = data[i].data[4] ;
		datablock[5]  = data[i].data[5] ;
		datablock[6]  = data[i].data[6] ;
		datablock[7]  = data[i].data[7] ; 
		datablock[8]  = data[i].data[8] ;
		datablock[9]  = data[i].data[9] ;
		datablock[10] = data[i].data[10];
		datablock[11] = data[i].data[11];
		datablock[12] = data[i].data[12];
		datablock[13] = data[i].data[13];
		datablock[14] = data[i].data[14];
		datablock[15] = data[i].data[15];
		block_write(i,datablock);
	}
	//Close the disk
	close_disk();	
	return 0;
}

//===============================================================================


int fs_truncate(int fildes, off_t length){
	int dirindex = oft[fildes].index;
	int origlen  = char3ToInt(dir[dirindex].fileLen[0],dir[dirindex].fileLen[1],dir[dirindex].fileLen[2]);
	
	//Can't extend length of file
	if (length > origlen){
		return -1;
	}

	//Can't have negative length
	if (length < 0){
		return -1;
	}

	oft[fildes].offset = 0;
	
	//Current Block	
	int currBlock = charToInt(dir[dirindex].firstBlock[0],dir[dirindex].firstBlock[1]);
	//Once at correct block, read and update offset
	//function assumes buf large enough to hold at least nbyte bytes
	int blocknum = length/16; //Where to store block_read results
	int prevBlock = currBlock;
	//Advance currBlock by offset as stored in OFT
	for (int i = 0; i < blocknum; i++){
		currBlock = char3ToInt(fat[currBlock].blockNum[0] ,
									fat[currBlock].blockNum[1],
									fat[currBlock].blockNum[2] );
	}
//	data[currBlock].data[0] = '0';
//	data[currBlock].data[1] = 'e';
//	data[currBlock].data[2] = 'o';
//	data[currBlock].data[3] = 'f';	
	if (length%16 != 0){
		int mod = length%16;
		for (int i = 0; i < 16; i++){
			if (i>=mod)
				data[currBlock].data[i] ='0';
		}
	}
	
	for (int i = blocknum; i < origlen/16; i++){
		prevBlock = currBlock;
		//Go to the next block first		
		fat[currBlock].status = '0';	
		currBlock = char3ToInt(fat[currBlock].blockNum[0] ,
								fat[currBlock].blockNum[1],
								fat[currBlock].blockNum[2] );
		fat[prevBlock].blockNum[0] = 'e';
		fat[prevBlock].blockNum[1] = 'o';
		fat[prevBlock].blockNum[2] = 'f';
	}			
	dir[dirindex].fileLen[0] = length / 100        + '0';
	dir[dirindex].fileLen[1] = (length % 100) / 10 + '0';
	dir[dirindex].fileLen[2] = length % 10         + '0';
	oft[fildes].offset = 0;
	return 0;
}


