a.exe: main.o circle.o rect.o shape.o
	g++ -g main.o circle.o rect.o shape.o

shape.o: shape.h shape.cpp
	g++ -c -g shape.cpp

circle.o: circle.cpp circle.h shape.h
	g++ -c -g circle.cpp

rect.o: rect.cpp rect.h shape.h
	g++ -c -g rect.cpp

main.o: main.cpp rect.h circle.h
	g++ -c -g main.cpp