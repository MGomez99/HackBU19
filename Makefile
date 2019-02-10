CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14 -static-libgcc -static-libstdc++

all:
	g++ $(CFLAGS) -c game.cpp -o game.o
	g++ $(CFLAGS) -c main.cpp -o main.o
	g++ $(CFLAGS) game.o main.o -o main
	
clean:
	rm -rf *.o main
run: all 
	./main
