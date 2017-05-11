CXX=g++
CPPFLAGS=-lstdc++ -std=c++11

DEPS=parsing.h shell.h
OBJ=parsing.o processing.o shell.o

.SUFFIXES: .o .cpp

shell: $(OBJ)
	$(CXX) $(OBJ) -o $@ $(CPPFLAGS)

shell.o: parsing.h processing.h shell.h
parsing.o: parsing.h
processing.o: processing.h

clean:
	rm -f *.o *~ shell
