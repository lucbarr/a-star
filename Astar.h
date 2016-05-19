#ifndef ASTAR_H
#define ASTAR_H

#include <queue>

#include "Node.h"
#include "Map.h"
#include "utils.h"

class Astar {
public:
    Astar(Map& algo_map);

    std::priority_queue< Node , std::vector<Node> , std::less<Node> > open_list_; //TODO: Decide whether lists will be
    std::priority_queue< Node , std::vector<Node> , std::less<Node> > closed_list_; // private or public.

    void gCostFunction(int x, int y);
    void hCostFunction(int x, int y);
    void fCostFunction(int x, int y); // TODO Refactor to pass Pos rather than x,y

    void setValues(int x, int y);

private:
   Map* algo_map_;
   std::vector<Node> path_;
};

Astar::Astar(Map& algo_map){
    algo_map_ = &algo_map;
}

void Astar::gCostFunction(int x, int y){
    int x_diff;
    int y_diff;
    x_diff = iabs (x-(algo_map_->getStartNode()).getPos().x);
    y_diff = iabs (y-(algo_map_->getStartNode()).getPos().y);

    algo_map_->map_[x].at(y).setGValue(ilow(x_diff,y_diff)*14 + iabs((x_diff-y_diff))*10);
    return ;
}

void Astar::hCostFunction(int x, int y){
    int x_diff;
    int y_diff;
    x_diff = iabs (x-(algo_map_->getStartNode()).getPos().x);
    y_diff = iabs (y-(algo_map_->getStartNode()).getPos().y);

    algo_map_->map_[x].at(y).setHValue((x_diff+y_diff)*10);
    return ;
}

void Astar::fCostFunction(int x, int y){
    algo_map_->map_[x].at(y).setFValue();
    return ;
}

void Astar::setValues(int x, int y){
    gCostFunction(x,y);
    hCostFunction(x,y);
    fCostFunction(x,y);
    return ;
}
#endif
