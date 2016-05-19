all: main.o map.o astar.o
	g++ main.o map.o astar.o -o a-star
main.o : main.cpp Map.h Astar.h
	g++ -c main.cpp
map.o : Map.h map.cpp Node.h utils.h
	g++ -c map.cpp
astar.o : Astar.h Node.h Map.h utils.h astar.cpp
	g++ -c astar.cpp
clean:
	rm *.o && rm a-star
run: all
	./a-star
