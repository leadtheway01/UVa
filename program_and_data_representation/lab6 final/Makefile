#Wright Kim
#wdk7bj
#Makefile

CXX = clang++ -O2 $(CXXFLAGS)
DEBUG = -Wall -g
.SUFFIXES: .0 .cpp

a.out: hashTable.o timer.o primenumber.o wordPuzzle.o
	$(CXX) $(DEBUG) wordPuzzle.cpp timer.cpp primenumber.cpp hashTable.cpp

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

primenumber.o: primenumber.cpp primenumber.h
	$(CXX) -c primenumber.cpp

#getWordInTable.o: getWordInTable.cpp getWordInTable.h
#	$(CXX) -c getWordInTable.cpp

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

clean:
	-rm *.o *~ 


dependency:
	clang++ -MM *.cpp
