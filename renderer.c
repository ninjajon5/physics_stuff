#include "renderer.h"
#include "sdl3_renderer.h"
#include "rectangle.h"

int renderer_init( enum Renderer renderer, int window_width, int window_height ) {
    switch( renderer ) {
        case TEXT:
            return 1 ;
        case SDL3:
            sdl3_renderer_init( window_width, window_height ) ;
            return 1 ;
        default:
            return 0 ;
    }
}


void renderer_draw_rectangle( enum Renderer renderer, struct rectangle *rectangle ) {
    switch( renderer ) {
        case TEXT:
            break ;
        case SDL3:
            sdl3_renderer_draw_rectangle( rectangle ) ;
        default:
            break ;
    }
} 

void renderer_shutdown( enum Renderer renderer ) {
    switch( renderer ) {
        case TEXT:
            break ;
        case SDL3:
            sdl3_renderer_shutdown() ;
        default:
            break ;
    }
}

