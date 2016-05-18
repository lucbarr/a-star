#ifndef NODE_H_
#define NODE_H_

#include "Pos.h"
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
    int getGValue() const { return g_value_; }
    int getHValue() const { return h_value_; }
    int getFValue() const { return (g_value_ + h_value_);}

    void setPos(Pos newpos) { position_ = newpos; }
    void setValid(bool validation) { is_valid_ = validation; }
    void setGValue(int g_value) { g_value_ = g_value; }
    void setHValue(int h_value) { h_value_ = h_value; }


    bool operator == ( const Node& node2){
    return ((position_ == node2.getPos()) && (is_valid_ == node2.getValid()));
    }
    bool operator < ( const Node& node2){
        if(this->getValid() && node2.getValid()){
            if(this->getFValue() < node2.getFValue()){
                return true;
            }
            else if(this->getFValue() == node2.getFValue()){
                return (this->getGValue() < node2.getGValue());
            }
            else{
                return false;
            }

        }
        else{
            return false;
        }
    } //TODO: do this right
private:
    Pos position_;
    bool is_valid_;
    int g_value_;
    int h_value_;
};



#endif