#main.make
algPath = ./algorithm
linearPath = ./linear


main:main.o log.o linear.o algorithm.o
	g++ -o main main.o log.o linear.o algorithm.o
	
main.o:main.cpp main.h
	g++ -c main.cpp
log.o:log.cpp
	g++ -c log.cpp

linear.o:$(linearPath)/linear.cpp $(linearPath)/linear.h
	g++ -c $< -o $@
algorithm.o:$(algPath)/expEval.cpp $(algPath)/algorithm.h
	g++ -c $< -o $@


clean:
	rm *.o
clear:
	rm main *.o

