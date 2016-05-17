#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>

#include "Node.h"
#include "utils.h"

class Map {
public:
    std::vector<Node> map_[MAX_SIZE];

    Map(const char* file_name);

    void setStartNode(Pos start_pos);
    void setEndNode(Pos end_pos);
    void setNofRows (int n_rows);
    void setNofColumns (int n_columns);

    int getNofRows() const { return n_of_rows_; }
    int getNofColumns() const { return n_of_columns_; }
    
    void printMap();
private:
    Node start_pos_;
    Node end_pos_;
    int n_of_rows_;
    int n_of_columns_;
};

#endif