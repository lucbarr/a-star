#ifndef UTILS_H
#define UTILS_H

#include "Pos.h"

const Pos UP ( 0 , -1 );
const Pos DOWN ( 0 , 1 );
const Pos RIGHT ( 1 , 0 );
const Pos LEFT ( -1 , 0 );
const Pos NULLPOS ( 0 , 0 );

const int MAX_SIZE = 20;

const int DIAG_W = 14;
const int VER_HOR_W = 10;

const char VALID_SYMBOL = '.'; // Anything different from valid, start and end
const char START_SYMBOL = 'S'; // symbols is considered invalid.
const char END_SYMBOL = 'E';


inline int iabs(int val){
    return val>0?val:-val;
}

inline int ilow(int a, int b){
    return a>b?b:a;
}

#endif
