#include "GameManager.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"

GameManager::GameManager(SDL_Renderer* _renderer){
    renderer=_renderer; 
    entity_manager=new EntityManager;
    event_manager=new EventManager;
    event_manager->add_event(new Event);
    entity_manager->add_entity(new Entity(entity_manager));

};

GameManager::~GameManager() {
    delete event_manager;
    delete entity_manager;
};

void GameManager::update(int dt, bool* running) {
    while (SDL_PollEvent(&e)!=0){
        if (e.type==SDL_QUIT){
            *(running)=false;
        };
    };
    event_manager->update();
};

void GameManager::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
};
