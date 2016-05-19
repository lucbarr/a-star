#ifndef POS_H
#define POS_H

struct Pos {
    int x,y;
    Pos(int a, int b) : x(a), y(b) {} ;
    Pos() : x(0), y(0) {} ;

    bool operator==(const Pos& pos2) const{
    return ((x == pos2.x) && (y == pos2.y));
    }
    Pos operator+(const Pos& pos2) const {
        return Pos( x+pos2.x, y+pos2.y );
    }
};

#endif
