#include <iostream>
#include <fstream>

#include "Map.h"

using namespace std;

int main (){
    Map map1("demo/map.txt");
    map1.printMap();
    return 0;
}