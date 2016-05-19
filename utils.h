#ifndef UTILS_H
#define UTILS_H

#include "Pos.h"

// Some orientation position constants

const Pos UP ( 0 , 1 );
const Pos DOWN ( 0 , -1 );
const Pos RIGHT ( 1 , 0 );
const Pos LEFT ( -1 , 0 );
const Pos NULLPOS ( 0 , 0 );

const int MAX_SIZE = 20; // Map maximum numbers of rows

const int DIAG_W = 14; // Weight for diagonals. is 14 because we are assuming the field is a set of squares
const int VER_HOR_W = 10; // Weight for Verticals and horizontals

const char VALID_SYMBOL = '.'; // Anything different from valid, start and end
const char START_SYMBOL = 'S'; // symbols is considered invalid.
const char END_SYMBOL = 'E';

// Absolute integer value function
inline int iabs(int val){
    return val>0?val:-val;
}
// Lowest integer value function
inline int ilow(int a, int b){
    return a>b?b:a;
}

#endif
