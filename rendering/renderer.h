#ifndef RENDERER_H
#define RENDERER_H

#include "../rectangles/rectangle.h"

enum Renderer {
    TEXT,
    SDL3
} ;

int renderer_update( char* argv[], enum Renderer* renderer ) ;
int renderer_init( enum Renderer renderer, int window_width, int window_height ) ;
void renderer_draw_rectangle( enum Renderer renderer, struct rectangle *rectangle ) ; 
int renderer_quit_requested( enum Renderer renderer ) ;
void renderer_shutdown( enum Renderer renderer ) ;

#endif
