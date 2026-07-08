#ifndef DICT_H
#define DICT_H

/*
returns timings for event loop
*/

struct time_info {
    int frame_count ;
    int second_count ;
    long long last_frame_start_time ;
    long long frame_start_time ;
    long long sleep_time ;
} ;

long long get_current_time_nanoseconds( void ) ;
void sleep_for_nanoseconds( long long nanoseconds_to_sleep_for ) ;
struct tm get_current_calendar_time( void ) ;
void print_loop_info( int FPS, int* frame_count, int* second_count ) ;

#endif
