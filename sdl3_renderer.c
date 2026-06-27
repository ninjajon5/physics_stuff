#include <SDL3/SDL.h>
#include "sdl3_renderer.h"

static SDL_Window *window = NULL ;
static SDL_Renderer * renderer = NULL ;

int sdl3_renderer_init( int window_width, int window_height ) {
    if( !SDL_Init( SDL_INIT_VIDEO ) ) return 0 ;
    if( !SDL_CreateWindowAndRenderer( "physics stuff", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer ) ) return 0 ;
    SDL_SetRenderLogicalPresentation( renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX ) ;
    
    return 1 ;
}

void sdl3_renderer_draw_rectangle( struct rectangle *rectangle ) {
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, SDL_ALPHA_OPAQUE ) ;
    SDL_RenderClear( renderer ) ;

    SDL_SetRenderDrawColor( renderer, 0, 0, 255, SDL_ALPHA_OPAQUE ) ;
    SDL_FRect sdl_rectangle = {
        .x = rectangle->x,
        .y = rectangle->y,
        .w = rectangle->width,
        .h = rectangle->height
    } ;
    SDL_RenderFillRect( renderer, &sdl_rectangle ) ;
    SDL_RenderPresent( renderer ) ;
}

void sd3_renderer_shutdown( void ) {
    SDL_DestroyRenderer( renderer ) ;
    SDL_DestroyWindow( window ) ;
    SDL_Quit() ;
}

