INCLUDE = ../include
SOURCE = ../source

test_hai: hai.o test_hai.o
	g++ -std=c++11 hai.o test_hai.o -o test_hai.test

test_hai.o: test_hai.cpp
	g++ -std=c++11 -c test_hai.cpp

test_tehai: tehai.o hai.o test_tehai.o
	g++ -std=c++11 tehai.o hai.o test_tehai.o -o test_tehai.test

test_tehai.o: test_tehai.cpp
	g++ -std=c++11 -c test_tehai.cpp

tehai.o: $(INCLUDE)/tehai.hpp $(SOURCE)/tehai.cpp $(INCLUDE)/hai.hpp
	g++ -std=c++11 -c $(SOURCE)/tehai.cpp

hai.o: $(INCLUDE)/hai.hpp $(SOURCE)/hai.cpp 
	g++ -std=c++11 -c $(SOURCE)/hai.cpp

clean:
	rm *.o *.test