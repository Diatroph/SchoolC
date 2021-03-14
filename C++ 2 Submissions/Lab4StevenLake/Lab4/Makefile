a.exe: main.o fstack.o
	g++ -g main.o fstack.o

fstack.o: fstack.cpp fstack.h
	g++ -g -c fstack.cpp

main.o: main.cpp fstack.h
	g++ -g -c main.cpp
