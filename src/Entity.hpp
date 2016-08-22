#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include "Transform.hpp"
#include "EntityManager.hpp"
#include "EventManager.hpp"
#include "GameManager.hpp"
#include <vector>

class EntityManager;
class EventManager;
class GameManager;

enum EntityType {
    TEST_ENTITY,
};

class Entity {
    public:
        Entity(GameManager*);
        ~Entity();
        unsigned int get_id(){return id;};
        unsigned int get_parent(){return parent;};
        std::vector<unsigned int> get_children(){return children;};

        void add_child(unsigned int other);
        void add_child_only(unsigned int other);
        void add_parent(unsigned int other);
        void add_parent_only(unsigned int other);
        void remove_child(unsigned int other);
        void remove_child_only(unsigned int other);
        void remove_children();
        void remove_parent();
        void remove_parent_only();
        void delete_children();

    protected: 
        unsigned int id;
        unsigned int parent;
        EntityManager* entity_manager;
        EventManager* event_manager;
        std::vector<unsigned int> children;
};

#endif
