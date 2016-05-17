#ifndef ASTAR_H
#define ASTAR_H

#include <vector.h>

#include "Node.h"

class Astar {
public:
    Astar(Map& algo_map);
 
    float gCostFunction(Node node_obj);
    float hCostFunction(Node node_obj);
private:
   Map* algo_map_;
   std::vector<Node> priority_nodes_;
   std::vector<Node> path_;
}

#endif