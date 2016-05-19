#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>

#include "Node.h"
#include "utils.h"


class Map {
public:
    std::vector<Node> map_[MAX_SIZE];

    // Map constructor. Takes a string with the name of the path to the file to build
    // your map. It obbeys the symbol protocol seen in utils.h
    Map(const char* file_name);

    // Set methods
    void setStartNode(Pos start_pos);
    void setEndNode(Pos end_pos);
    void setNofRows (int n_rows);
    void setNofColumns (int n_columns);

    // Get methods.
    int getNofRows() const { return n_of_rows_; }
    int getNofColumns() const { return n_of_columns_; }
    Node getStartNode() const { return start_node_; }
    Node getEndNode() const { return end_node_; }

    // Print method.
    void printMap();

private:
    Node start_node_;
    Node end_node_;
    int n_of_rows_;
    int n_of_columns_;
};

#endif
