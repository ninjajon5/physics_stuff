#include "utils/event_loop_time.h"
#include "rectangles/rectangle.h"
#include "rendering/renderer.h"
#include <stdio.h>


/*
TODO
- add bounce
- add directional launch
*/

static const int DEBUG = 0 ;
enum Renderer renderer = SDL3 ;
const int FPS = 60 ;
static const long long FRAME_TIME_NANOSECONDS = 1000000000LL / FPS ;
// APIs expect nanoseconds, so this avoids conversion
// long long to handle the large counts from using nanoseconds

static const float starting_x = 300.0 ;
static const float starting_y = 200.0 ;
static const float starting_width = 15.0 ;
static const float starting_height = 15.0 ;
static const float starting_y_velocity = -10.0 ;
static const float gravity = 0.2 ;


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


int main( int argc, char* argv[] ) {
    if( !_handle_arguments( argc, argv, &renderer ) ) return 1 ;

    if( !renderer_init( renderer, 800, 600 ) ) return 1 ;
    
    struct rectangle rectangles[ 1024 ] ;
    rectangles[0] = (struct rectangle) { 
        .x = starting_x,
        .y = starting_y,
        .width = starting_width,
        .height = starting_height,
        .y_velocity = starting_y_velocity,
        .deflectable = 1
    } ;
    rectangles[1] = (struct rectangle) {
       .x = 250.0,
       .y = 300.0,
       .width = 100.0,
       .height = 15.0,
       .deflectable = 0 
    } ;

    struct time_info time_info = {} ;
    int running = 1 ;
    while( running ) {
        long long frame_start_time = get_current_time_nanoseconds() ;

        if( renderer_quit_requested( renderer ) ) running = 0 ;

        rectangle_apply_gravity( &rectangles[0], gravity ) ;
        rectangle_apply_velocity( &rectangles[0] ) ;
        rectangle_apply_collisions( rectangles, 2 ) ;

        renderer_clear( renderer ) ;
        renderer_draw_rectangle( renderer, &rectangles[0] ) ;
        renderer_draw_rectangle( renderer, &rectangles[1] ) ;
        renderer_present( renderer ) ;       

        long long frame_elapsed_time = get_current_time_nanoseconds() - frame_start_time ;
        time_info.sleep_time = FRAME_TIME_NANOSECONDS - frame_elapsed_time ;
        sleep_for_nanoseconds( time_info.sleep_time ) ;
        
        if( DEBUG ) debug( FPS, &time_info ) ;
        time_info.last_frame_start_time = frame_start_time ;
    }

    renderer_shutdown( renderer ) ;

    return 0 ;
}

