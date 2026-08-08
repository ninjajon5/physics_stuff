#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H
#include "../rectangles/rectangle.h"

int text_renderer_init() ;
void text_renderer_clear( void ) ;
void text_renderer_draw_rectangle( struct rectangle *rectangle ) ; 
void text_renderer_present( void ) ;
int text_renderer_quit_requested( void ) ;
void text_renderer_shutdown( void ) ;

#endif

