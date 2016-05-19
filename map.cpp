#include "Map.h"

#include <iostream>
#include <string.h>

// In this file you can find the methods declared in Map.h definitions

// Set methods

void Map::setStartNode(Pos start_pos){
    start_node_.setPos(start_pos);
    start_node_.setValid(true);
    return ;
}

void Map::setEndNode(Pos end_pos){
    end_node_.setPos(end_pos);
    end_node_.setValid(true);
    return ;
}


void Map::setNofColumns(int n_columns){
    n_of_columns_ = n_columns;
    return ;
}

void Map::setNofRows(int n_rows){
    n_of_rows_ = n_rows;
    return ;
}

// Constructor method

Map::Map(const char* file_name){
    int i,j;
    this->setNofColumns(0);
    std::string aux_string;

    Pos aux_pos;

    std::ifstream mapfile;
    mapfile.open(file_name);

    for (i =0; !mapfile.eof() ; ++i){
        getline ( mapfile, aux_string );
        for (j = 0; j < aux_string.size() ; ++j){

            aux_pos.x = i;
            aux_pos.y = j;

            if(aux_string.at(j) == START_SYMBOL){
                this->setStartNode( aux_pos );
                map_[i].push_back (Node ( aux_pos, true ));
            }
            else if (aux_string.at(j) == END_SYMBOL){
                this->setEndNode( aux_pos );
                map_[i].push_back (Node ( aux_pos, true ));
            }
            else if (aux_string.at(j) == VALID_SYMBOL){
                map_[i].push_back (Node ( aux_pos, true ));
            }
            else {
                map_[i].push_back (Node ( aux_pos, false ));
            }
        }
    if (j > this->getNofColumns()){
        this->setNofColumns(j);
    }
    this->setNofRows(i+1);
}
}

// Print method

void Map::printMap(){
    for (int i = 0 ; i < this->getNofRows()-1 ; ++i ){
        for (int j = 0 ; j < this->getNofColumns()-1 ; ++j ){
            if(map_[i].at(j) == this->getStartNode()){
                std::cout << START_SYMBOL;
            }
            else if (map_[i].at(j) == this->getEndNode()){
                std::cout << END_SYMBOL;
            }
            else if(map_[i].at(j).getValid()){
                std::cout << VALID_SYMBOL;
            }
            else {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
    return ;
}
