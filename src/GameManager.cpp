#include "GameManager.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Console.hpp"
#include <iostream>

class EntityManager;

GameManager::GameManager(SDL_Renderer* _renderer){
    renderer=_renderer; 
    entity_manager=new EntityManager(this);
    event_manager=new EventManager(this);
    entity_manager->add_entity(new Console(this)); 
    event_manager->add_event(new TestEvent);
    event_manager->update();
    //entity_manager->remove_entity(1);
    //event_manager->add_event(new TestEvent);
   // event_manager->update();

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
