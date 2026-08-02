#include "rectangle.h"

void rectangle_apply_gravity( struct rectangle *rectangle, float gravity ) {
    rectangle->y_velocity += gravity ;
}

void rectangle_apply_velocity( struct rectangle *rectangle ) {
    rectangle->y += rectangle->y_velocity ;
    rectangle->x += rectangle->x_velocity ;
}

int rectangle_is_collision( 
    struct rectangle *rectangle_A,
    struct rectangle *rectangle_B
) {
    float rectangle_A_highest_y = rectangle_A->y ;
    float rectangle_A_lowest_y = (
        rectangle_A->y + rectangle_A->height
    ) ;

    float rectangle_B_highest_y = rectangle_B->y ;
    float rectangle_B_lowest_y = (
        rectangle_B->y + rectangle_B->height
    ) ;

    if( rectangle_A_lowest_y < rectangle_B_highest_y ) {
        return 0 ;
    } else if ( rectangle_A_highest_y > rectangle_B_lowest_y ) {
        return 0 ;
    } else {
        return 1 ;
    }
}
