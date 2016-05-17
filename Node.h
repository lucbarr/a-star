#ifndef NODE_H_
#define NODE_H_

#include "pos.h"
#include "utils.h"

class Node {
public:
    Node(Pos position, bool is_valid) : 
        position_(position),
        is_valid_(is_valid)
        {};
   
    Node():
        position_(NULLPOS),
        is_valid_(false)
        {};
    Node(const Node& obj):
        position_( obj.position_ ),
        is_valid_( obj.is_valid_ )
        {};
    Pos getPos() const { return position_; }
    bool getValid() const { return is_valid_; }

    void setPos(Pos newpos) { position_ = newpos; }
    void setValid(bool validation) { is_valid_ = validation; }


private:
    Pos position_;
    bool is_valid_;
};


#endif