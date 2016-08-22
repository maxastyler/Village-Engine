#ifndef _CONSOLE_HPP
#define _CONSOLE_HPP

#include "Entity.hpp"
#include "Event.hpp"
#include <iostream>
#include "GameManager.hpp"

class Console: public Entity{
    public:
        Console(GameManager*); 
    private:
        void print_data(Event* event); 
};

#endif
