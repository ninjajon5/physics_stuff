#include <time.h>
#include <stdio.h>
#include "event_loop_time.h"

#define _POSIX_C_SOURCE 199309L // feature test macro to allow POSIX clock_gettime and CLOCK_MONOTONIC
#define FPS 60
#define FRAME_TIME_NANOSECONDS ( 1000000000LL / FPS )
// APIs expect nanoseconds, so this avoids conversion
// long long to handle the large counts from using nanoseconds


int main( void ) {
    int running = 1 ;
    int frame_count = 1 ;
    int second_count = 0 ;

    while( running ) {
        long long frame_start_time = get_current_time_nanoseconds() ;

        if( frame_count == FPS ) {
            frame_count = 1 ;
            second_count++ ;
        } else {
            frame_count++ ;
        }
        
        struct tm current_calendar_time = get_current_calendar_time() ;
        printf( "%d - %d - %d\n", frame_count, second_count, current_calendar_time.tm_sec ) ;

        long long frame_elapsed_time = get_current_time_nanoseconds() - frame_start_time ;
        sleep_for_nanoseconds( FRAME_TIME_NANOSECONDS - frame_elapsed_time ) ;
    }

    return 0 ;
}
