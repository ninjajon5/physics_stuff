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

    TASSERT( rectangle_is_collision( 
        &top_rectangle,
        &bottom_rectangle
    ) ) ;

    return 1 ;
}

int _4_test_horizontally_overlapping_rectangles_detect_collision( void ) {
    struct rectangle left_rectangle = {
        .x = 0.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0
    } ;

    struct rectangle right_rectangle = {
        .x = 1.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0
    } ;

    TASSERT( rectangle_is_collision( 
        &left_rectangle,
        &right_rectangle
    ) ) ;

    return 1 ;
}

int _5_test_rectangles_only_overlapping_vertically_do_not_detect_collision( void ) {
    struct rectangle top_rectangle = {
        .x = 0.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0
    } ;

    struct rectangle bottom_rectangle = {
        .x = 100.0,
        .y = 1.0,
        .width = 2.0,
        .height = 2.0
    } ;

    TASSERT( !rectangle_is_collision( 
        &top_rectangle,
        &bottom_rectangle
    ) ) ;

    return 1 ;
}

int _6_test_rectangles_only_overlapping_horizontally_do_not_detect_collision( void ) {
    struct rectangle left_rectangle = {
        .x = 0.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0
    } ;

    struct rectangle right_rectangle = {
        .x = 1.0,
        .y = 100.0,
        .width = 2.0,
        .height = 2.0
    } ;

    TASSERT( !rectangle_is_collision( 
        &left_rectangle,
        &right_rectangle
    ) ) ;

    return 1 ;
}

int _7_test_colliding_rectangles_invert_y_velocity( void ) {
     struct rectangle top_rectangle = {
        .x = 0.0,
        .y = 0.0,
        .width = 2.0,
        .height = 2.0,
        .y_velocity = 1.0
    } ;

    struct rectangle bottom_rectangle = {
        .x = 0.0,
        .y = 1.0,
        .width = 2.0,
        .height = 2.0,
        .y_velocity = 0.0
    } ;

    struct rectangle rectangles[2] = { top_rectangle, bottom_rectangle } ;

    rectangle_apply_collisions( rectangles, 2 ) ;

    TASSERT( rectangles[0].y_velocity == -1.0 ) ;

    return 1 ;
}

int _8_test_colliding_frozen_rectangles_does_not_invert_y_velocity( void ) {
    // placeholder
}


test_function tests[] = {
    _1_test_apply_gravity_increases_y_velocity,
    _2_test_apply_velocity_updates_position_correctly,
    _3_test_vertically_overlapping_rectangles_detect_collision,
    _4_test_horizontally_overlapping_rectangles_detect_collision,
    _5_test_rectangles_only_overlapping_vertically_do_not_detect_collision,
    _6_test_rectangles_only_overlapping_horizontally_do_not_detect_collision,
    _7_test_colliding_rectangles_invert_y_velocity
} ;
int test_count = sizeof( tests ) / sizeof( tests[0] ) ;

int main( void ) {
    run_tests( tests, test_count ) ;
    return 0 ;
}
