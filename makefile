CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: program1.o Star.o Planet.o Vector.o List.o
	g++ -o program1 program1.o Star.o Planet.o List.o
	
program1.o: program1.cpp Star.cpp Star.h Planet.cpp Planet.h Vector.cpp Vector.h List.cpp List.h
	g++ -c $(CFLAGS) program1.cpp -o program1.o

Star.o: Star.cpp Star.h
	g++ -c $(CFLAGS) Star.cpp -o Star.o

Planet.o: Planet.cpp Planet.h
	g++ -c $(CFLAGS) Planet.cpp -o Planet.o

Vector.o:
	g++ -c $(CFLAGS) Vector.cpp -o Vector.o

List.o:
	g++ -c $(CFLAGS) List.cpp -o List.o

run: all
	./program1

memcheck: all
	valgrind ./program1

clean:
	rm -rf *.o program1
