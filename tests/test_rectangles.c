#include "test.h"
#include "../rectangles/rectangle.h"


int _1_test_apply_gravity_increases_y_velocity( void ) {
    float starting_y_velocity = 0.0 ;
    float gravity = 1.0 ;

    struct rectangle rectangle = {
        .y_velocity = starting_y_velocity
    } ; 

    rectangle_apply_gravity( &rectangle, gravity ) ;

    TASSERT( rectangle.y_velocity > starting_y_velocity ) ;

    return 1 ;
}

int _2_test_apply_velocity_updates_position_correctly( void ) {
    float starting_x = 0.0 ;
    float starting_y = 0.0 ;
    float starting_x_velocity = 1.0 ;
    float starting_y_velocity = 2.0 ;

    struct rectangle rectangle = {
        .x = starting_x,
        .y = starting_y,
        .x_velocity = starting_x_velocity,
        .y_velocity = starting_y_velocity
    } ;

    rectangle_apply_velocity( &rectangle ) ;

    TASSERT(
        rectangle.x > starting_x &&
        rectangle.y > starting_y
    ) ;

    return 1 ;
}

int _3_test_vertically_overlapping_rectangles_detect_collision( void ) {
    struct rectangle top_rectangle = {
        .x = 0.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0
    } ;

    struct rectangle bottom_rectangle = {
        .x = 0.0,
        .y = 1.0,
        .width = 2.0,
        .height = 2.0
    } ;

    struct rectangle rectangles[2] ;
    rectangles[0] = top_rectangle ;
    rectangles[1] = bottom_rectangle ; 

    TASSERT( rectangle_is_collision( rectangles ) ) ;

    return 1 ;
}


test_function tests[] = {
    _1_test_apply_gravity_increases_y_velocity,
    _2_test_apply_velocity_updates_position_correctly
} ;
int test_count = sizeof( tests ) / sizeof( tests[0] ) ;

int main( void ) {
    run_tests( tests, test_count ) ;
    return 0 ;
}
