#include "renderer.h"
#include "text_renderer.h"
#include "sdl3_renderer.h"
#include "rectangle.h"
#include <stdio.h>

int renderer_init( enum Renderer renderer, int window_width, int window_height ) {
    printf("checking renderer\n") ;
    switch( renderer ) {
        case TEXT:
            printf("TEXT\n") ;
            return text_renderer_init() ;
        case SDL3:
            printf("SDL3\n") ;
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

