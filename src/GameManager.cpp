#include "GameManager.hpp"

void GameManager::update(int dt, bool* running) {
    while (SDL_PollEvent(&e)!=0){
        if (e.type==SDL_QUIT){
            *(running)=false;
        };
    };
    event_manager.update();
};

void GameManager::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
};
