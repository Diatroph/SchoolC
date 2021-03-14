a.exe: main.o person.o
	g++ -g main.o person.o

person.o: person.cpp person.h
	g++ -g -c person.cpp

main.o: main.cpp tlist.h person.h
	g++ -c -g main.cpp
