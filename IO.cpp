/*****************************************************************************************
/* File: IO.cpp
/* Desc: Handles IO with SDL2 library
*/

#include "IO.h"
#include <cstdio>
#include <SDL2/SDL.h>  // Include the SDL2 header

static SDL_Window *mWindow;     // Window
static SDL_Renderer *mRenderer; // Renderer
static Uint32 mColors[COLOR_MAX] = {0x000000ff, // Colors
                                      0xff0000ff, 0x00ff00ff, 0x0000ffff,
                                      0x00ffffff, 0xff00ffff, 0xffff00ff,
                                      0xffffffff};

/* 
======================================                                    
Init
====================================== 
*/
IO::IO() 
{
    InitGraph();
}


/* 
======================================                                    
Clear the screen to black
====================================== 
*/
void IO::ClearScreen() 
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255); // Set color to black
    SDL_RenderClear(mRenderer); // Clear the renderer
}


/* 
======================================                                    
Draw a rectangle of a given color

Parameters:
>> pX1, pY1:         Upper left corner of the rectangle
>> pX2, pY2:         Lower right corner of the rectangle
>> pC                Rectangle color
====================================== 
*/
void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC)
{
    SDL_Rect rect = {pX1, pY1, pX2 - pX1, pY2 - pY1};
    SDL_SetRenderDrawColor(mRenderer, (mColors[pC] >> 24) & 0xFF, (mColors[pC] >> 16) & 0xFF, (mColors[pC] >> 8) & 0xFF, 255);
    SDL_RenderFillRect(mRenderer, &rect); // Draw the rectangle
}


/* 
======================================                                    
Return the screen height
====================================== 
*/
int IO::GetScreenHeight()
{
    int h;
    SDL_GetWindowSize(mWindow, NULL, &h);
    return h;
}


/* 
======================================                                    
Update screen
====================================== 
*/
void IO::UpdateScreen()
{
    SDL_RenderPresent(mRenderer); // Present the renderer
}


/* 
======================================                                    
Keyboard Input
====================================== 
*/
int IO::Pollkey()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        switch (event.type) {
            case SDL_KEYDOWN:
                return event.key.keysym.sym;
            case SDL_QUIT:
                exit(3);
        }
    }
    return -1;
}

/* 
======================================                                    
Keyboard Input
====================================== 
*/
int IO::Getkey()
{
    SDL_Event event;
    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
            break;
        if (event.type == SDL_QUIT)
            exit(3);
    };
    return event.key.keysym.sym;
}

/* 
======================================                                    
Keyboard Input
====================================== 
*/
int IO::IsKeyDown(int pKey)
{
    const Uint8 *mKeytable = SDL_GetKeyboardState(NULL);
    return mKeytable[pKey];
}

/* 
======================================                                    
SDL Graphical Initialization
====================================== 
*/
int IO::InitGraph()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    atexit(SDL_Quit);

    // Create window
    mWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!mWindow) {
        fprintf(stderr, "Couldn't create window: %s\n", SDL_GetError());
        return 2;
    }

    // Create renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer) {
        fprintf(stderr, "Couldn't create renderer: %s\n", SDL_GetError());
        return 3;
    }

    return 0;
}
