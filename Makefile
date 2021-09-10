#main.make
algPath = ./algorithm
linearPath = ./linear
treePath = ./tree


main:main.o log.o linear.o tree.o expEval.o LRU.o
	g++ main.o log.o linear.o tree.o expEval.o LRU.o -o main
	
main.o:main.cpp main.h
	g++ -c main.cpp
log.o:log.cpp
	g++ -c log.cpp

linear.o:$(linearPath)/linear.cpp $(linearPath)/linear.h
	g++ -c $< -o $@
tree.o:$(treePath)/binaryTree.cpp $(treePath)/binaryTree.h
	g++ -c $< -o $@

expEval.o:$(algPath)/expEval.cpp $(algPath)/algorithm.h
	g++ -c $< -o $@
LRU.o:$(algPath)/LRU.cpp $(algPath)/algorithm.h $(algPath)/models.h
	g++ -c $< -o $@


clean:
	rm *.o
clear:
	rm main *.o

