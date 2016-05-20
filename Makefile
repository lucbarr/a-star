all: a-star

a-star : main.o map.o astar.o
	g++  main.o map.o astar.o -o a-star
%.o: %.cpp
	g++ -c main.cpp map.cpp astar.cpp
clean:
	rm *.o && rm a-star
run: all
	./a-star
