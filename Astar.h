#ifndef ASTAR_H
#define ASTAR_H

#include "Node.h"
#include "Map.h"

class Astar {
public:
    Astar(Map& algo_map);
 
    int gCostFunction(int x, int y);
    int hCostFunction(Node& node_obj);
private:
   Map* algo_map_;
   std::vector<Node> priority_nodes_;
   std::vector<Node> path_;
};

Astar::Astar(Map& algo_map){
    algo_map_ = &algo_map;
}

int Astar::gCostFunction(int x, int y){

    algo_map_->map_[x].at(y).setGValue(10);
}
#endif