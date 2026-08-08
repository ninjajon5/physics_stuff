#include "rectangle.h"

void _rectangle_apply_collisions_after_current_rectangle(
    struct rectangle *current_rectangle,
    int current_rectangle_index,
    struct rectangle *rectangles,
    int rectangle_count
) ;
void _rectangle_deflect( struct rectangle *rectangle ) ;


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
        _rectangle_apply_collisions_after_current_rectangle(
            current_rectangle, i, rectangles, rectangle_count
        ) ;
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

void _rectangle_apply_collisions_after_current_rectangle( 
    struct rectangle *current_rectangle,
    int current_rectangle_index,
    struct rectangle *rectangles,
    int rectangle_count
) {
    int starting_comparison_index = current_rectangle_index + 1 ;
    for( int j = starting_comparison_index ; j < rectangle_count ; j++ ) {
        struct rectangle *comparison_rectangle = &rectangles[j] ;
        if( rectangle_is_collision( current_rectangle, comparison_rectangle ) ) {
            _rectangle_deflect( current_rectangle ) ;
            _rectangle_deflect( comparison_rectangle ) ;
        }
    }
}

void _rectangle_deflect( struct rectangle *rectangle ) {
    if( rectangle->deflectable ) rectangle->y_velocity *= -1 ;
}
