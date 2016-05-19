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
    algo.setValues(1,2);
    algo.setValues(0,1);
    algo.setValues(0,0);
    algo.closed_list_.push(map1.map_[0].at(1));
    algo.closed_list_.push(map1.map_[0].at(0));
    algo.closed_list_.push(map1.map_[1].at(1));
    algo.closed_list_.push(map1.map_[1].at(2));

    while(!algo.closed_list_.empty()){
        cout << algo.closed_list_.top().getFValue() << endl;
        algo.closed_list_.pop();
    }
    return 0;
}
