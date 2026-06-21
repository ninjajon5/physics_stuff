#ifndef RECTANGLE_H
#define RECTANGLE_H

/*
rectangle struct, with dimensions and position
*/

struct rectangle {
    float x ;
    float y ;
    float width ;
    float height ;
} ;

void rectangle_apply_gravity( struct rectangle ) ;

#endif
