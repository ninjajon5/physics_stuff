#!/bin/bash  
gcc -o physics main.c utils/event_loop_time.c rectangles/rectangle.c rendering/renderer.c rendering/text_renderer.c rendering/sdl3_renderer.c $(pkg-config --cflags --libs sdl3)
