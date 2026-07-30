#include "test.h"

int _1_test_demo( void ) {
    return 1 ;
}

test_function tests[] = {
    _1_test_demo
} ;
int test_count = sizeof( tests ) / sizeof( tests[0] ) ;

int main( void ) {
    run_tests( tests, test_count ) ;
    return 0 ;
}
