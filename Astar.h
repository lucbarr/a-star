#ifndef ASTAR_H
#define ASTAR_H

#include <queue>

#include "Node.h"
#include "Map.h"
#include "utils.h"

class Astar {
public:

    // Algorithm class constructor. Takes a map address
    // so it can do its algorithm iterations without
    // having to allocate another map

    Astar(Map& algo_map);

    // Open and closed lists priority queues. They must obbey operator overload defined in Node.h.
    // The algorith is biased to check for lesser f valued nodes. If two nodes has same f values,
    // it checks for the g values if they are the lowest.


    std::priority_queue <Node, std::vector<Node> , NodeCompare > closed_list_; //TODO: Decide whether lists will be
    std::priority_queue <Node, std::vector<Node> , NodeCompare > open_list_; // private or public.

    // g, h and f cost functions methods. It takes the position of the Node in the map you gave to your Astar
    // and sets g, h and f costs for that node.

    void gCostFunction(int x, int y);
    void hCostFunction(int x, int y);
    void fCostFunction(int x, int y); // TODO Refactor to pass Pos rather than x,y

    std::vector<Node> findPath();
    // This method here is for simplifying the evaluation.
    void setValues(int x, int y);
    void generateAdj(int x, int y);
private:
   Map* algo_map_;
   std::vector<Node> path_;
};

#endif
