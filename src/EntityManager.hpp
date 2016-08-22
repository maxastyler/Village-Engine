#ifndef _ENTITY_MANAGER_HPP
#define _ENTITY_MANAGER_HPP

#include <map>
#include "Entity.hpp"
#include "GameManager.hpp"

class Entity;
class GameManager;

class EntityManager {

    public:
        EntityManager(GameManager* _game_manager);
        ~EntityManager();

        unsigned int add_entity(Entity*);
        void remove_entity(unsigned int id);
        void remove_entity_only(unsigned int id);
        void remove_all_entities();
        Entity* entity_at(unsigned int id);

        unsigned int get_current_id(){return current_id;};

    protected:
        unsigned int current_id;
        std::map<unsigned int, Entity*> entities;
        GameManager* game_manager;

};

#endif
