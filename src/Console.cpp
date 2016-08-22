#include "Console.hpp"
#include <functional>
#include "GameManager.hpp"
#include <iostream>

Console::Console(GameManager* game_manager):Entity(game_manager){
    event_manager->add_listener_all(id, new std::function<void(Event* e)>([&](Event* e){this->print_data(e);})); 
};

void Console::print_data(Event* e){
    std::cout << e->id << std::endl;
};
