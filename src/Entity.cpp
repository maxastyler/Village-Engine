#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Event.hpp"
#include <functional>
#include <iostream>
#include <algorithm>


Entity::Entity(GameManager* game_manager){
    entity_manager=game_manager->get_entity_manager();
    event_manager=game_manager->get_event_manager();
    id=entity_manager->get_current_id();
};

Entity::~Entity() {
    event_manager->remove_listener(id);
    delete_children();
};

void Entity::add_child(unsigned int other){
    if (std::find(children.begin(), children.end(), other)==children.end() && other!=parent && other!=id){
        children.push_back(other);
        entity_manager->entity_at(other)->add_parent_only(this->id);
    };
};

void Entity::add_child_only(unsigned int other){
    if (std::find(children.begin(), children.end(), other)==children.end() && other!=parent && other!=id)
        children.push_back(other);
};

void Entity::add_parent(unsigned int other){
    if (std::find(children.begin(), children.end(), other)==children.end() && other!=id){
        parent=other;
        entity_manager->entity_at(other)->add_child_only(this->id);
    };
};

void Entity::add_parent_only(unsigned int other){
    if (std::find(children.begin(), children.end(), other)==children.end() && other!=parent && other!=id)
        parent=other;
};

void Entity::remove_child(unsigned int other){
    entity_manager->entity_at(other)->remove_parent_only();
    children.erase(std::remove(children.begin(), children.end(), other), children.end()); 
};

void Entity::remove_child_only(unsigned int other){
    children.erase(std::remove(children.begin(), children.end(), other), children.end()); 
};

void Entity::remove_children() {
    for (auto i: children)
        entity_manager->entity_at(i)->remove_parent_only();
    children.clear();
};

void Entity::remove_parent(){
    if (entity_manager->entity_at(parent))
        entity_manager->entity_at(parent)->remove_child_only(this->id);
    parent=0;
};

void Entity::remove_parent_only(){
    parent=0;
};

void Entity::delete_children(){ 
    for (auto i: children){
        entity_manager->remove_entity(i);
    };
};
