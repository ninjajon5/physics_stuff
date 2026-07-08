#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L // feature test macro to allow POSIX clock_gettime and CLOCK_MONOTONIC
#endif
#include <time.h>
#include <stdio.h>
#include "event_loop_time.h"


long long get_current_time_nanoseconds( void ) {
    struct timespec timespec ;
    clock_gettime( CLOCK_MONOTONIC, &timespec ) ; // monotonic for time passed, not wall time (i.e. unaffected by system clock)
    long long current_time_seconds = timespec.tv_sec * 1000000000LL ;
    long long current_time_nanoseconds = timespec.tv_nsec ;
    return current_time_seconds + current_time_nanoseconds ;
}


void sleep_for_nanoseconds( long long nanoseconds_to_sleep_for ) {
    if ( nanoseconds_to_sleep_for <= 0 ) return ;
    struct timespec timespec = {
        .tv_sec = nanoseconds_to_sleep_for / 1000000000LL, // integer division - extracts the number of completed seconds
        .tv_nsec = nanoseconds_to_sleep_for % 1000000000LL // modulo - gets the remainder, the number of nanoseconds after the last completed seconds
    } ;
    nanosleep( &timespec, NULL ) ;
}


struct tm get_current_calendar_time( void ) {
    time_t raw_time = time( NULL ) ;
    return *localtime( &raw_time ) ;
}

void print_loop_info( int FPS, int* frame_count, int* second_count ) {
    if( *frame_count == FPS ) {
        *frame_count = 1 ;
        (*second_count)++ ;
    } else {
        (*frame_count)++ ;
    }
    
    struct tm current_calendar_time = get_current_calendar_time() ;
    int second_count_to_calendar_diff = *second_count - current_calendar_time.tm_sec ;
    printf( "F%d - S%d - C%d - SC%d\n", 
            *frame_count, 
            *second_count, 
            current_calendar_time.tm_sec,
            second_count_to_calendar_diff
    ) ;
}

void debug( int FPS, struct time_info* time_info ) {
    print_loop_info( FPS, &(time_info->frame_count), &(time_info->second_count) ) ;
    
    long long elapsed_time = time_info->frame_start_time - time_info->last_frame_start_time ;
    printf( "Start time diff: %lld\n", elapsed_time ) ;
    printf( "Sleep time: %lld\n", time_info->sleep_time ) ;
}
