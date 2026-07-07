#include "utils/event_loop_time.h"
#include "rectangles/rectangle.h"
#include "rendering/renderer.h"
#include <stdio.h>


/*
TODO
- refactor debug to live in utils/ and use a time info struct
- accept user input to exit loop
- add tests to rectangle
- add collision
- add bounce
- add directional launch
*/

enum Renderer renderer = SDL3 ;
const int FPS = 60 ;
static const long long FRAME_TIME_NANOSECONDS = 1000000000LL / FPS ;
// APIs expect nanoseconds, so this avoids conversion
// long long to handle the large counts from using nanoseconds
static const int DEBUG = 1 ;


int _handle_arguments( int argc, char* argv[], enum Renderer* renderer ) {
    if( argc > 2 ) {
        printf( "only 1 argument is accepted" ) ;
        return 0 ;
    } else if( argc == 2 ) {
        return renderer_update( argv, renderer ) ; 
    } else if( argc == 1 ) {
        return 1 ;
    } else {
        return 0 ;
    }
}


void _debug( int FPS, long long frame_start_time, long long last_frame_start_time, long long sleep_time, int* frame_count, int* second_count ) {
    print_loop_info( FPS, frame_count, second_count ) ;
    printf( "Spare time: %lld\n", FRAME_TIME_NANOSECONDS - ( frame_start_time - last_frame_start_time ) ) ;
    printf( "Sleep time: %lld\n", sleep_time ) ;
}


int main( int argc, char* argv[] ) {
    if( !_handle_arguments( argc, argv, &renderer ) ) return 1 ;

    if( !renderer_init( renderer, 800, 600 ) ) return 1 ;
    
    struct rectangle rectangles[ 1024 ] ;
    rectangles[0] = (struct rectangle) { 
        .x = 300.0,
        .y = 0.0,
        .width = 15.0,
        .height = 15.0,
        .y_velocity = 0.0 
    } ;

    int frame_count = 0 ;
    int second_count = 0 ;
    int running = 1 ;
    long long last_frame_start_time = 0 ;
    while( running ) {
        long long frame_start_time = get_current_time_nanoseconds() ;

        if( renderer_quit_requested( renderer ) ) running = 0 ;

        rectangle_apply_gravity( &rectangles[0], 1.0 ) ;
        rectangle_apply_velocity( &rectangles[0] ) ;

        renderer_draw_rectangle( renderer, &rectangles[0] ) ;
        
        long long frame_elapsed_time = get_current_time_nanoseconds() - frame_start_time ;
        long long sleep_time = FRAME_TIME_NANOSECONDS - frame_elapsed_time ;
        sleep_for_nanoseconds( sleep_time ) ;
        
        if( DEBUG ) _debug( FPS, frame_start_time, last_frame_start_time, sleep_time, &frame_count, &second_count ) ;
        last_frame_start_time = frame_start_time ;
    }

    renderer_shutdown( renderer ) ;

    return 0 ;
}

