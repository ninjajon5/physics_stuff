#ifndef DICT_H
#define DICT_H

/*
returns timings for event loop
*/

long long get_current_time_nanoseconds( void ) ;
void sleep_for_nanoseconds( long long nanoseconds_to_sleep_for ) ;
struct tm get_current_calendar_time( void ) ;
void print_loop_info( void ) ;

#endif
