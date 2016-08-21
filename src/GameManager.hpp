#ifndef _GAME_MANAGER_HPP
#define _GAME_MANAGER_HPP

#include "EventManager.hpp"
#include "EntityManager.hpp"
#include <SDL2/SDL.h>

class EntityManager;
class EventManager;

class GameManager {

    public:
        GameManager(SDL_Renderer* _renderer);
        ~GameManager();
        void update(int, bool*);
        void render();

    private:
        EventManager* event_manager;
        EntityManager* entity_manager;
        SDL_Renderer* renderer; 
        SDL_Event e;
};

#endif
