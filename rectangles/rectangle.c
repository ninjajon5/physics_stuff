#include "rectangle.h"

void rectangle_apply_gravity( struct rectangle *rectangle, float gravity ) {
    rectangle->y_velocity += gravity ;
}

void rectangle_apply_velocity( struct rectangle *rectangle ) {
    rectangle->y += rectangle->y_velocity ;
    rectangle->x += rectangle->x_velocity ;
}
