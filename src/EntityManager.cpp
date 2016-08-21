#include "EntityManager.hpp"

EntityManager::EntityManager() {
    current_id=0;
};

EntityManager::EntityManager(unsigned int _current_id) {
    current_id=_current_id;
};

EntityManager::~EntityManager() {
    remove_all_entities();    
};

unsigned int EntityManager::add_entity(Entity* e){
    entities[current_id]=e;
    return current_id++;
};

void EntityManager::remove_entity(unsigned int id) { 
    delete entities[id];
    entities.erase(id);
};

void EntityManager::remove_all_entities() {
    for (auto ent: entities) {
        delete ent.second;
    };
    entities.clear();
};
