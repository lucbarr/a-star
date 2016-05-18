#include <iostream>
#include <fstream>

#include "Map.h"
#include "Astar.h"

using namespace std;

int main (){
    Map map1("demo/map.txt");
    Astar algo(map1);
    map1.printMap();
    algo.gCostFunction(1, 1);
    cout << map1.map_[1].at(1).getGValue();

    return 0;
}
