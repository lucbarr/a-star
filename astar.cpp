#include "Astar.h"

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
