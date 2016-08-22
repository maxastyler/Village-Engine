#ifndef _EVENT_MANAGER_HPP
#define _EVENT_MANAGER_HPP

#include <vector>
#include <queue>
#include <map>
#include <functional>
#include "Event.hpp"
#include "GameManager.hpp"

class GameManager;

class EventManager {
    public: 
        EventManager(GameManager* _game_manager);
        ~EventManager();
        void update();
        void add_event(Event*);
        void add_listener(EventType, unsigned int, std::function<void(Event*)>);
        void add_listener_all(unsigned int, std::function<void(Event*)>);

        //Removes the listener from that event type by global id
        void remove_listener(EventType, unsigned int);
        //Removes the listener from all event types by global id
        void remove_listener(unsigned int);

        //Removes all listeners from every event type
        void remove_all_listeners();
        //Removes all listeners from that event type
        void remove_all_listeners(EventType);
    private:
        std::map<
            EventType, std::map<unsigned int, std::function<void(Event*)>>
                > listeners; 
        std::queue<Event*> events;
        GameManager* game_manager;

};
#endif
