all: main.o Number.o
	g++ main.o Number.o -o hw6
.PHONY: all

main.o: main.cpp
	g++ -c main.cpp
	
Number.o: Number.cpp Number.h
	g++ -c Number.cpp	

clean:
	rm main.o Number.o hw3
	
