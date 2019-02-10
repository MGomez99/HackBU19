CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14 -static-libgcc -static-libstdc++
l = game
s = main
$(l):
	g++ $(CFLAGS) -c -o $(l).o $(l).cpp
$(s): $(l)
	g++ $(CFLAGS) -c -o $(s).o $(s).cpp
all: $(l) $(s)
	g++ $(l).o $(s).o -o $(s)

clean:
	rm -rf *.o $(l)
run: all 
	./main
