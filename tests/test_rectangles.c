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


test_function tests[] = {
    _1_test_apply_gravity_increases_y_velocity
} ;
int test_count = sizeof( tests ) / sizeof( tests[0] ) ;

int main( void ) {
    run_tests( tests, test_count ) ;
    return 0 ;
}
