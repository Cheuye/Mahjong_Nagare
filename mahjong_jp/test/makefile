INCLUDE = ../include
SOURCE = ../source

OPTION = -std=c++11

test_hai: hai.o test_hai.o
	g++ $(OPTION) hai.o test_hai.o -o test_hai.test

test_hai.o: test_hai.cpp
	g++ $(OPTION) -c test_hai.cpp

test_tehai: tehai.o hai.o test_tehai.o
	g++ $(OPTION) tehai.o hai.o test_tehai.o -o test_tehai.test

test_tehai.o: test_tehai.cpp
	g++ $(OPTION) -c test_tehai.cpp

test_util: test_util.o hai.o tehai.o util.o
	g++ $(OPTION) test_util.o hai.o tehai.o util.o -o test_util.test

test_util.o: test_util.cpp
	g++ $(OPTION) -c test_util.cpp

util.o: $(INCLUDE)/util.hpp $(SOURCE)/util.cpp $(INCLUDE)/tehai.hpp
	g++ $(OPTION) -c $(SOURCE)/util.cpp

tehai.o: $(INCLUDE)/tehai.hpp $(SOURCE)/tehai.cpp $(INCLUDE)/hai.hpp
	g++ $(OPTION) -c $(SOURCE)/tehai.cpp

hai.o: $(INCLUDE)/hai.hpp $(SOURCE)/hai.cpp 
	g++ $(OPTION) -c $(SOURCE)/hai.cpp

clean:
	rm *.o *.test