all: main.o map.o
	g++ main.o map.o -o a-star
main.o : main.cpp Map.h Astar.h
	g++ -c main.cpp
map.o : Map.h map.cpp Node.h utils.h
	g++ -c map.cpp
clean:
	rm *.o && rm a-star
run: all
	./a-star
