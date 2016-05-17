#include <iostream>
#include <fstream>

#include "Map.h"
#include "Astar.h"

using namespace std;

int main (){
    Map map1("demo/map.txt");
    Astar algo(map1);
    map1.printMap();
    return 0;
}