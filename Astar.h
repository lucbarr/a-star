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

#endif
