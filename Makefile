#main.make

main:main.o linear.o
	g++ -o main main.o linear.o
	
main.o:main.cpp
	g++ -c main.cpp
linear.o:linear.cpp
	g++ -c linear.cpp


clean:
	rm main.o linear.o
clear:
	rm main main.o linear.o

