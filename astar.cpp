#include "Astar.h"

// Astar class methods declared in Astar.h definitions

// Constructor method. Takes a map address and alow the algorithm class
// to see it.
Astar::Astar(Map& algo_map){
    algo_map_ = &algo_map;
}

// G cost method. The "real" value function is calculated for a Node in (x,y) position from algo_map_
void Astar::gCostFunction(int x, int y){
    int x_diff;
    int y_diff;
    x_diff = iabs (x-(algo_map_->getEndNode()).getPos().x);
    y_diff = iabs (y-(algo_map_->getEndNode()).getPos().y);

    algo_map_->map_[x].at(y).setGValue(ilow(x_diff,y_diff)*DIAG_W + iabs((x_diff-y_diff))*10);
    return ;
}

// H cost method. The heuristic value function is set with this method.
void Astar::hCostFunction(int x, int y){
    int x_diff;
    int y_diff;
    x_diff = iabs (x-(algo_map_->getStartNode()).getPos().x);
    y_diff = iabs (y-(algo_map_->getStartNode()).getPos().y);

    algo_map_->map_[x].at(y).setHValue((x_diff+y_diff)*10);
    return ;
}

// F cost is simply the sum of the others (see Node.h)
void Astar::fCostFunction(int x, int y){
    algo_map_->map_[x].at(y).setFValue();
    return ;
}

// There will be always evaluated all costs at once, so I
// wrote this method to simplify things up
void Astar::setValues(int x, int y){
    gCostFunction(x,y);
    hCostFunction(x,y);
    fCostFunction(x,y);
    return ;
}

void Astar::generateAdj(int x, int y){
    Node aux_node = algo_map_->map_[x].at(y);
    for (int i = -1; i < 2 ; ++i){
        if ( (x+i < algo_map_->getNofRows()) && (x+i >= 0) ){
            for (int j = -1; j < 2 ; ++j){
            if (( y+j < algo_map_->getNofColumns()) && (y+j >= 0)){
                if (aux_node.getValid()){
                    this->setValues(x+i,y+j);
                }
            }
        }
    }
    }
}

std::vector<Node> Astar::findPath(){
    Node aux_node;
    open_list_.push(algo_map_->getStartNode());
    while(!open_list_.empty()){
        aux_node = open_list_.top();
        int x = aux_node.getPos().x;
        int y = aux_node.getPos().y;
        open_list_.pop();
        this->generateAdj(x, y);
        for (int i = -1; i < 2 ; ++i){
            if ( (x+i < algo_map_->getNofRows()) && (x+i >= 0) ){
                for (int j = -1; j < 2 ; ++j){
                    if (( y+j < algo_map_->getNofColumns()) && (y+j >= 0)){
                        open_list_.push(algo_map_->map_[x+i].at(y+j));
                    }
                }
            }
        }
    closed_list_.push(aux_node);
    }
}
