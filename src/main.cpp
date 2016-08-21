#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include "LTimer.hpp"

int WINDOW_WIDTH=640;
int WINDOW_HEIGHT=480;

const int FRAME_TIME=1000./60.;

SDL_Window* window;
SDL_Renderer* renderer;

LTimer fpsTimer;
LTimer capTimer;

void init();
void quit();
void main_loop();

int main(int argc, char* argv[]) {

    init();
    
    fpsTimer.start();
    main_loop();

    quit();

    return 0;
};

void init() {
    SDL_Init(SDL_INIT_VIDEO);
    window=SDL_CreateWindow("ViewSystem", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
};

void quit() {
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
};

void main_loop() {
    
    SDL_Event e;
    bool running=true;

    SDL_Texture* bitmapTex=SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("../Resources/spritetest.png"));

    while (running) {

        capTimer.start();

        while (SDL_PollEvent(&e)!=0) {
            if (e.type==SDL_QUIT) 
                running=false;
        };

        int frame_ticks=capTimer.get_ticks();
        if (frame_ticks<FRAME_TIME) {
            SDL_Delay(FRAME_TIME-frame_ticks);
        };
    };

};
