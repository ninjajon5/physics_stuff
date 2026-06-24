#include <time.h>
#include <stdio.h>
#include "event_loop_time.h"
#include "rectangle.h"

#define _POSIX_C_SOURCE 199309L // feature test macro to allow POSIX clock_gettime and CLOCK_MONOTONIC
#define FPS 60
#define FRAME_TIME_NANOSECONDS ( 1000000000LL / FPS )
// APIs expect nanoseconds, so this avoids conversion
// long long to handle the large counts from using nanoseconds


int main( void ) {
    int running = 1 ;

    struct rectangle rectangles[ 1024 ] ;
    rectangles[0] = (struct rectangle){ .y = 0.0, .y_velocity = 0.0 } ;
    
    while( running ) {
        long long frame_start_time = get_current_time_nanoseconds() ;

        rectangle_apply_gravity( &rectangles[0], 2.0 ) ;
        rectangle_apply_velocity( &rectangles[0] ) ;
        printf( "%f\n", rectangles[0].y ) ;

        long long frame_elapsed_time = get_current_time_nanoseconds() - frame_start_time ;
        sleep_for_nanoseconds( FRAME_TIME_NANOSECONDS - frame_elapsed_time ) ;
    }

    return 0 ;
}
