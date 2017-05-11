#Wright Kim
#wdk7bj
#Makefile

CXX = clang++ $(CXXFLAGS)
DEBUG = -Wall -g
.SUFFIXES: .0 .cpp

#a.out: $(CXX) $(DEBUG)

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

clean:
	-rm *.o *~ 


dependency:
	clang++ -MM *.cpp
