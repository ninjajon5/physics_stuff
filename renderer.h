#ifndef RENDERER_H
#define RENDERER_H

#include "rectangle.h"

int renderer_init( int window_width, int window_height ) ;
void renderer_draw_rectangle( struct rectangle *rectangle ) ; 
void renderer_shutdown( void ) ;

#endif
