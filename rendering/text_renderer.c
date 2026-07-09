#include <stdio.h>
#include "text_renderer.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <sys/select.h>
#endif

char _text_renderer_get_input_character( void ) ;

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

char _text_renderer_get_input_character( void ) {
    #ifdef _WIN32
        if( _khbit() ) { // check the keyboard for input, otherwise return 0
            return _getch() ; // read character from the buffer
        }
    #else
        struct timeval tv = { 0, 0 } ; // needed for polling - set values to 0 to indicate no wait time
        
        fd_set fds ; // create a file descriptor sect
        FD_ZERO( &fds ) ; // clear all file descriptors from the set
        FD_SET( STDIN_FILENO, &fds ) ; // add standard input to the set

        select( STDIN_FILENO + 1, &fds, NULL, NULL, &tv ) ; // monitor the set, reading it instantly
        if( FD_ISSET( STDIN_FILENO, &fds ) ) { // check if the select() flagged the set as ready to read
            char ch ;
            if( read( STDIN_FILENO, &ch, 1 ) == 1 ) { // attempt to read the ch
                return ch ; // if successful, return it
            }
        }
    #endif
        return 0 ;
}

