#include <time.h>
#include <stdio.h>
#include <SDL3/SDL.h>
#include "event_loop_time.h"
#include "rectangle.h"
#include "renderer.h"

#define _POSIX_C_SOURCE 199309L // feature test macro to allow POSIX clock_gettime and CLOCK_MONOTONIC

/*
TODO
- refactor to separate renderer
- add tests to rectangle
- add collision
- add bounce
- add directional launch
*/

enum Renderer {
    TEXT,
    SDL3
}
static const enum Renderer renderer = SDL3 ;
static const int FPS = 60 ;
static const long long FRAME_TIME_NANOSECONDS = 1000000000LL / FPS ;
// APIs expect nanoseconds, so this avoids conversion
// long long to handle the large counts from using nanoseconds


int main( void ) {
    if( !renderer_init( 800, 600 ) ) return 1 ;
    
    struct rectangle rectangles[ 1024 ] ;
    rectangles[0] = (struct rectangle){ 
        .x = 300.0,
        .y = 0.0,
        .width = 15.0,
        .height = 15.0,
        .y_velocity = 0.0 
    } ;
    
    int running = 1 ;
    while( running ) {
        long long frame_start_time = get_current_time_nanoseconds() ;

        SDL_Event event ;
        if( VISUALISE ) {
            while( SDL_PollEvent( &event ) ) {
                if( event.type == SDL_EVENT_QUIT ) running = 0 ;
            }
        }

        rectangle_apply_gravity( &rectangles[0], 1.0 ) ;
        rectangle_apply_velocity( &rectangles[0] ) ;
        if( VISUALISE ) {
            SDL_Log( "%f\n", rectangles[0].y ) ;
        } else { 
            printf( "%f\n", rectangles[0].y ) ; 
        }

        if( VISUALISE ) { renderer_draw_rectangle( &rectangles[0] ) ; }

        long long frame_elapsed_time = get_current_time_nanoseconds() - frame_start_time ;
        sleep_for_nanoseconds( FRAME_TIME_NANOSECONDS - frame_elapsed_time ) ;
    }

    if( VISUALISE ) { renderer_shutdown() ; }

    return 0 ;
}
