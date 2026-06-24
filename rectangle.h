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
    float x_velocity ;
    float y_velocity ;
} ;

void rectangle_apply_gravity( struct rectangle *rectangle, float gravity ) ;
void rectangle_apply_velocity( struct rectangle *rectangle ) ;

#endif
