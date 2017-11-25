INCLUDE = ../include
SOURCE = ../source

test_hai: hai.o test_hai.o
	g++ -std=c++11 hai.o test_hai.o -o test_hai

hai.o: $(INCLUDE)/hai.hpp $(SOURCE)/hai.cpp
	g++ -std=c++11 -c $(SOURCE)/hai.cpp

test_hai.o: test_hai.cpp
	g++ -std=c++11 -c test_hai.cpp

clean:
	rm *.o test_hai