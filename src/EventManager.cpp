#include "EventManager.hpp"
#include <functional>
#include "Event.hpp"

void EventManager::update() {
    while(!events.empty()) {
        Event* current=(events.front());
        for (auto& ent: listeners[current->id]) {
            ent.second(current);  
        };
        delete events.front();
        events.pop();
    };
};

void EventManager::add_listener(EventType e, unsigned int id, std::function<void(Event*)> func) {
    listeners[e][id]=func; 
};

void EventManager::add_event(Event* e){
    events.push(e);
};

void EventManager::remove_listener(EventType e, unsigned int id) {
    listeners[e].erase(id);
};

void EventManager::remove_listener(unsigned int id) {
    for (auto& element: listeners) {
        element.second.erase(id);
    };
};

void EventManager::remove_all_listeners(EventType e) {
    listeners.erase(e);
};

void EventManager::remove_all_listeners() {
    listeners.clear(); 
};
