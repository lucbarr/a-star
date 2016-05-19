#ifndef NODE_H_
#define NODE_H_

#include "Pos.h"
#include "utils.h"

class Node {
public:

    // Constructors

    Node(Pos position, bool is_valid) :
        position_(position),
        is_valid_(is_valid)
        {};

    Node():
        position_(NULLPOS),
        is_valid_(false),
        g_value_( 999 ),
        h_value_( 999 )
        {};
    Node(const Node& obj):
        position_( obj.position_ ),
        is_valid_( obj.is_valid_ ),
        g_value_( obj.g_value_ ),
        h_value_( obj.h_value_ )
        {};

    // Get methods

    Pos getPos() const { return position_; }
    bool getValid() const { return is_valid_; }
    int getGValue() const { return g_value_; }
    int getHValue() const { return h_value_; }
    int getFValue() const { return (g_value_ + h_value_);}

    // Set methods

    void setPos(Pos newpos) { position_ = newpos; }
    void setValid(bool validation) { is_valid_ = validation; }
    void setGValue(int g_value) { g_value_ = g_value; }
    void setHValue(int h_value) { h_value_ = h_value; }
    void setFValue() { f_value_ = g_value_+h_value_; }

    // Overloaded class comparison operators
    // TODO: Refactor this (Astar.h priority queue comparison not working)

    bool operator == ( const Node& node2) const {
    return ((position_ == node2.getPos()) && (is_valid_ == node2.getValid()));
    }
    bool operator < ( const Node& node2) const {
            if(f_value_ < node2.getFValue()){
                return true;
            }
            else if(f_value_ == node2.getFValue()){
                return (g_value_ < node2.getGValue());
            }
            else{
                return false;
            }
    }

private:
    Pos position_;
    bool is_valid_;
    int g_value_;
    int h_value_;
    int f_value_;
};



#endif
