all: Teststring

Teststring: Teststring.cpp string.o
	g++ -Wall -o Teststring Teststring.cpp string.o 

string.o: string.h string.cpp
	g++ -Wall -o string.o string.cpp -c
