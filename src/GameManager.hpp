#ifndef _GAME_MANAGER_HPP
#define _GAME_MANAGER_HPP

#include "EventManager.hpp"
#include <SDL2/SDL.h>

class GameManager {

    public:
        GameManager(SDL_Renderer* _renderer):renderer(_renderer){};
        void update(int, bool*);
        void render();

    private:
        EventManager event_manager;
        SDL_Renderer* renderer; 
        SDL_Event e;

};

#endif
