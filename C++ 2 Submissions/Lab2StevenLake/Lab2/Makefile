a.exe: main.o bankAccount.o
	g++ -g main.o bankAccount.o

bankAccount.o: bankAccount.cpp bankAccount.h
	g++ -g -c bankAccount.cpp bankAccount.h

main.o: main.cpp bankAccount.h
	g++ -g -c main.cpp 