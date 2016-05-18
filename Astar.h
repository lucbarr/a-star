#ifndef ASTAR_H
#define ASTAR_H

#include "Node.h"
#include "Map.h"
#include "utils.h"

class Astar {
public:
    Astar(Map& algo_map);

    int gCostFunction(int x, int y);
    int hCostFunction(int x, int y);
private:
   Map* algo_map_;
   std::vector<Node> priority_nodes_;
   std::vector<Node> path_;
};

Astar::Astar(Map& algo_map){
    algo_map_ = &algo_map;
}

int Astar::gCostFunction(int x, int y){
    int x_diff;
    int y_diff;
    x_diff = iabs (x-(algo_map_->getStartNode()).getPos().x);
    y_diff = iabs (y-(algo_map_->getStartNode()).getPos().y);

    algo_map_->map_[x].at(y).setGValue(ilow(x_diff,y_diff)*14 + iabs((x_diff-y_diff))*10);
}

#endif
