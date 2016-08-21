#ifndef _ENTITY_MANAGER_HPP
#define _ENTITY_MANAGER_HPP

#include <map>
#include "Entity.hpp"

class Entity;

class EntityManager {

    public:
        EntityManager();
        EntityManager(unsigned int);
        ~EntityManager();

        unsigned int add_entity(Entity*);
        void remove_entity(unsigned int id);
        void remove_all_entities();

        unsigned int get_current_id(){return current_id;};

    protected:
        unsigned int current_id;
        std::map<unsigned int, Entity*> entities;

};

#endif
