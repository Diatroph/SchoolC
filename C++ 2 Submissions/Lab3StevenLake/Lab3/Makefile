a.exe: car.o main.o company.o
	g++ -g car.o main.o company.o

company.o: company.cpp company.h
	g++ -c -g company.cpp	

car.o: car.cpp car.h
	g++ -c -g car.cpp

main.o: main.cpp car.h
	g++ -c -g main.cpp