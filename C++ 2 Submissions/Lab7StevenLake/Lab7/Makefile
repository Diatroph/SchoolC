a.exe: node.o iqueue.o main.o
	g++ -g node.o iqueue.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

iqueue.o: iqueue.cpp iqueue.h node.h
	g++ -c -g iqueue.cpp

main.o: main.cpp iqueue.h
	g++ -c -g main.cpp
