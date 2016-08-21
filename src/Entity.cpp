#include "Entity.hpp"
#include "EntityManager.hpp"

Entity::Entity(EntityManager* _entity_manager){
    id=_entity_manager->get_current_id();
    entity_manager=_entity_manager;
};

Entity::~Entity() {
    remove_parent();
    for (auto child: children) {
        entity_manager->remove_entity(child.first);
    };
};

void Entity::add_parent(Entity* other) {
    parent=other;
    other->add_child(this);
};

void Entity::add_child(Entity* other) {
    children[other->get_id()]=other;
    other->add_parent(this);
};

void Entity::remove_child(unsigned int id) {
    children[id]->remove_parent();
    children.erase(id);
};

void Entity::remove_child(Entity* other) {
    children[other->get_id()]->remove_parent();
    children.erase(other->get_id());
};

void Entity::remove_children() {
    for (auto c: children) {
        c.second->remove_parent();
    };
    children.clear();
};

void Entity::remove_parent() {
    parent->remove_child(this->id);
    parent=nullptr; 
};
