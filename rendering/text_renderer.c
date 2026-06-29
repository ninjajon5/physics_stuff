#include <stdio.h>
#include "text_renderer.h"

int text_renderer_init() {
    return 1 ;
}

void text_renderer_draw_rectangle( struct rectangle *rectangle ) {
    printf( "%f\n", rectangle->y ) ;
}

int text_renderer_quit_requested() {
    return 0 ;
}

void text_renderer_shutdown( void ) {
    // no shutdown needed
}

