#ifndef UTILS_H
#define UTILS_H

#include "Pos.h"

const Pos UP ( 0 , -1 );
const Pos DOWN ( 0 , 1 );
const Pos RIGHT ( 1 , 0 );
const Pos LEFT ( -1 , 0 );
const Pos NULLPOS ( 0 , 0 );

const int MAX_SIZE = 20;

const char VALID_SYMBOL = '.'; // Anything different from valid, start and end
const char START_SYMBOL = 'S'; // symbols is considered invalid.
const char END_SYMBOL = 'E';

#endif