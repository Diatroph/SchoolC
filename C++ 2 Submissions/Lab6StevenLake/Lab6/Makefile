a.exe: main.o fqueue.o 
	g++ -g main.o fqueue.o 

fqueue.o: fqueue.cpp fqueue.h
	g++ -c -g fqueue.cpp 
	
main.o: fqueue.h main.cpp
	g++ -c -g  main.cpp