#ifndef ASTAR_H
#define ASTAR_H

#include "Node.h"
#include "Map.h"

class Astar {
public:
    Astar(Map& algo_map);
 
    float gCostFunction(Node node_obj);
    float hCostFunction(Node node_obj);
private:
   Map* algo_map_;
   std::vector<Node> priority_nodes_;
   std::vector<Node> path_;
};

Astar::Astar(Map& algo_map){
    algo_map_ = &algo_map;
}
#endif