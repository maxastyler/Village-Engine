#include "EntityManager.hpp"
#include <iostream>

//Entity id of 0 is a null entity

EntityManager::EntityManager(GameManager* _game_manager) {
    current_id=1;
    game_manager=_game_manager;
};

EntityManager::~EntityManager() {
    remove_all_entities();    
};

unsigned int EntityManager::add_entity(Entity* e){
    entities[current_id]=e;
    return current_id++;
};

void EntityManager::remove_entity(unsigned int id) { 
    entities[entities[id]->get_parent()]->remove_child_only(id);
    for(auto i: entities[id]->get_children())
        remove_entity(i);
    delete entities[id];
    entities.erase(id);
};

void EntityManager::remove_entity_only(unsigned int id){
    entities[entities[id]->get_parent()]->remove_child_only(id);
    for (auto i: entities[id]->get_children())
        entities[i]->remove_parent_only();
    delete entities[id];
    entities.erase(id);
};

void EntityManager::remove_all_entities() {
    for (auto it= entities.begin(); it!=entities.end(); ++it) {
        it->second->remove_children();
        it->second->remove_parent();
    };

    for (auto it=entities.begin();it!=entities.end(); ++it) {
        delete it->second;
    };
    entities.clear();
};

Entity* EntityManager::entity_at(unsigned int id) {
    if (entities.count(id)>0)
        return entities[id];
    else
        return nullptr;
};
