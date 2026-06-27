#ifndef SDL3_RENDERER_H
#define SDL3_RENDERER_H

#include "rectangle.h"

int sdl3_renderer_init( int window_width, int window_height ) ;
void sdl3_renderer_draw_rectangle( struct rectangle *rectangle ) ; 
int sdl3_quit_requested( void ) ;
void sdl3_renderer_shutdown( void ) ;

#endif

