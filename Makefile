CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
l = game
s = main
$(l):
	g++ $(CFLAGS) -c $(l).cpp
$(s): 
	g++ $(CFLAGS) -c $(s).cpp
all: $(l) $(s)
	g++ $(l).o $(s).o -o $(s)

clean:
	rm -rf *.o $(l)
run: all 
	./main
