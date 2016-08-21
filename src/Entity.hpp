#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include "GameManager.hpp"
#include "Transform.hpp"
#include "EntityManager.hpp"
#include <map>

class EntityManager;

class Entity {
    public:
        Entity(EntityManager*);
        ~Entity();
        unsigned int get_id(){return id;};
        void add_parent(Entity* other);
        void add_child(Entity* other);
        void remove_child(unsigned int id);
        void remove_child(Entity* other);
        void remove_children();
        void remove_parent();

    protected: 
        Transform transform;
        unsigned int id;
        Entity* parent;
        EntityManager* entity_manager;
        std::map<unsigned int, Entity*> children;
};

#endif
