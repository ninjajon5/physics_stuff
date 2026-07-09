#include <stdio.h>
#include "text_renderer.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    
    static struct termios original_termios ; // original terminal settings
    static int terminal_modified = 0 ;
#endif

char _text_renderer_get_input_character( void ) ;

int text_renderer_init() {
    #ifndef _WIN32
        if( tcgetattr( STDIN_FILENO, &original_termios ) == 0 ) { // attempt to write STDIN_FILENO attributes into original_termios
            struct termios raw_termios = original_termios ;

            raw_termios.c_lflag &= ~( ICANON | ECHO ) ; // disable canonical mode and echo, so we don't need to press enter and typed characters aren't echoed
            
            raw_termios.c_cc[ VMIN ] = 0 ; // minimum characters to read
            raw_termios.c_cc[ VTIME ] = 0 ; // timeout is 0 (non-blocking read)
            
            tcsetattr( STDIN_FILENO, TCSAFLUSH, &raw_termios ) ;
            terminal_modified = 1 ;
        }
    #endif
        return 1 ;
}

void text_renderer_draw_rectangle( struct rectangle *rectangle ) {
    printf( "%f\n", rectangle->y ) ;
}

int text_renderer_quit_requested() {
    char input_character = _text_renderer_get_input_character() ;
    if( input_character == 'q' ) return 1 ;
    return 0 ;
}

void text_renderer_shutdown( void ) {
    #ifndef _WIN32
        if( terminal_modified ) {
            tcsetattr( STDIN_FILENO, TCSAFLUSH, &original_termios ) ; // restore original termios settings
        }
    #endif
}

char _text_renderer_get_input_character( void ) {
    #ifdef _WIN32
        if( _kbhit() ) { // check the keyboard for input, otherwise return 0
            return _getch() ; // read character from the buffer
        }
    #else
        char ch ;
        if( read( STDIN_FILENO, &ch, 1 ) == 1 ) {
            return ch ;
        }
    #endif
        return 0 ;
}

