#include "renderer.h"
#include "text_renderer.h"
#include "sdl3_renderer.h"
#include "../rectangles/rectangle.h"
#include <string.h>
#include <stdio.h>

int renderer_update( char* argv[], enum Renderer* renderer ) {
    if ( strcmp( argv[1], "text" ) == 0 ) {
        *renderer = TEXT ;
        return 1 ;
    } else if ( strcmp( argv[1], "sdl3" ) == 0 ) {
        *renderer = SDL3 ;
        return 1 ;
    } else {
        printf( "%s is not a valid argument", argv[1] ) ;
        return 0 ;
    }
}

int renderer_init( enum Renderer renderer, int window_width, int window_height ) {
    switch( renderer ) {
        case TEXT:
            return text_renderer_init() ;
        case SDL3:
            return sdl3_renderer_init( window_width, window_height ) ;
        default:
            return 0 ;
    }
}


void renderer_draw_rectangle( enum Renderer renderer, struct rectangle *rectangle ) {
    switch( renderer ) {
        case TEXT:
            text_renderer_draw_rectangle( rectangle ) ;
            break ;
        case SDL3:
            sdl3_renderer_draw_rectangle( rectangle ) ;
            break ;
        default:
            break ;
    }
} 

int renderer_quit_requested( enum Renderer renderer ) {
    switch( renderer ) {
        case TEXT:
            return text_renderer_quit_requested() ;
        case SDL3:
            return sdl3_quit_requested() ;
        default:
            return 0 ;
    }
}

void renderer_shutdown( enum Renderer renderer ) {
    switch( renderer ) {
        case TEXT:
            text_renderer_shutdown() ;
            break ;
        case SDL3:
            sdl3_renderer_shutdown() ;
            break ;
        default:
            break ;
    }
}

