#include <math.h>

#include "geom.h"


float distance_p(  Point p1,  struct Point p2 ){
    // разницы между Point и struct Point нет
    return sqrt( powf(p2.x-p1.x, 2.0) + powf(p2.y-p1.y, 2.0) );
}
