#include <SDL3/SDL.h>
#include "sdl3_renderer.h"

static SDL_Window *window = NULL ;
static SDL_Renderer * renderer = NULL ;

int sdl3_renderer_init( int window_width, int window_height ) {
    if( !SDL_Init( SDL_INIT_VIDEO ) ) return 0 ;
    if( !SDL_CreateWindowAndRenderer( 
                "physics stuff", 
                window_width, 
                window_height, 
                SDL_WINDOW_RESIZABLE, 
                &window, 
                &renderer 
    ) ) return 0 ;
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

    SDL_Log( "%f\n", rectangle->y ) ;
}

int sdl3_quit_requested() {
    SDL_Event event ;
    while( SDL_PollEvent( &event ) ) {
        if( event.type == SDL_EVENT_QUIT ) return 1 ;
        if( event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_q ) return 1 ;
    }
    return 0 ;
}

void sdl3_renderer_shutdown( void ) {
    SDL_DestroyRenderer( renderer ) ;
    SDL_DestroyWindow( window ) ;
    SDL_Quit() ;
}

