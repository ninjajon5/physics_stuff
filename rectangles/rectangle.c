#include "rectangle.h"

void rectangle_apply_gravity( struct rectangle *rectangle, float gravity ) {
    rectangle->y_velocity += gravity ;
}

void rectangle_apply_velocity( struct rectangle *rectangle ) {
    rectangle->y += rectangle->y_velocity ;
    rectangle->x += rectangle->x_velocity ;
}

void rectangle_apply_collisions( struct rectangle *rectangles, int rectangle_count ) {
    for( int i = 0 ; i < ( rectangle_count - 1 ) ; i++ ) {
        struct rectangle *current_rectangle = &rectangles[i] ;
        
        for( int j = ( i + 1 ) ; j < rectangle_count ; j++ ) {
            struct rectangle *comparison_rectangle = &rectangles[j] ;
            if( rectangle_is_collision( current_rectangle, comparison_rectangle ) ) {
                current_rectangle->y_velocity *= -1 ;
                comparison_rectangle->y_velocity *= 1 ;
            }
        }
    }
}

int rectangle_is_collision( 
    struct rectangle *rectangle_A,
    struct rectangle *rectangle_B
) {
    float rectangle_A_highest_y = rectangle_A->y ;
    float rectangle_A_lowest_y = (
        rectangle_A->y + rectangle_A->height
    ) ;
    float rectangle_A_leftmost_x = rectangle_A->x ;
    float rectangle_A_rightmost_x = (
        rectangle_A->x + rectangle_A->width
    ) ;

    float rectangle_B_highest_y = rectangle_B->y ;
    float rectangle_B_lowest_y = (
        rectangle_B->y + rectangle_B->height
    ) ;
    float rectangle_B_leftmost_x = rectangle_B->x ;
    float rectangle_B_rightmost_x = (
        rectangle_B->x + rectangle_B->width
    ) ;


    if( rectangle_A_lowest_y < rectangle_B_highest_y ) {
        return 0 ;
    } else if ( rectangle_A_highest_y > rectangle_B_lowest_y ) {
        return 0 ;
    } else if ( rectangle_A_rightmost_x < rectangle_B_leftmost_x ) {
        return 0 ;
    } else if ( rectangle_A_leftmost_x > rectangle_B_rightmost_x ) {
        return 0 ;
    } else {
        return 1 ;
    }
}
