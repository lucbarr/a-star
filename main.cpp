#include <iostream>
#include <fstream>

#include "Map.h"
#include "Astar.h"

using namespace std;

int main (){
    Map map1("demo/map.txt");
    Astar algo(map1);
    map1.printMap();
    algo.setValues(1,1);
    algo.setValues(1,0);
    algo.setValues(2,0);
    algo.open_list_.push(map1.map_[1].at(1));
    algo.open_list_.push(map1.map_[1].at(0));
    algo.open_list_.push(map1.map_[2].at(0));
    while (!algo.open_list_.empty()){
        cout << algo.open_list_.top().getFValue() << endl;
        algo.open_list_.pop();
    }

    return 0;
}
