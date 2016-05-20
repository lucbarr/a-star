#include <iostream>
#include <fstream>

#include "Map.h"
#include "Astar.h"

using namespace std;

int main (){
    Map map1("demo/map.txt");
    Astar algo(map1);
    map1.printMap();
    std::priority_queue <Node> open_list;
    algo.setValues(1,1);
    algo.setValues(1,0);
    algo.setValues(2,0);
    open_list.push(map1.map_[1].at(1));
    open_list.push(map1.map_[1].at(0));
    open_list.push(map1.map_[2].at(0));
    while (!open_list.empty()){
        cout << open_list.top().getFValue() << endl;
        open_list.pop();
    }

    return 0;
}
