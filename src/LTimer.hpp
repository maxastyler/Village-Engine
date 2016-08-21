#ifndef _LTIMER_HPP
#define _LTIMER_HPP

#include "SDL2/SDL.h"

class LTimer{

    public:
        LTimer();
        void start();
        void stop();
        void pause();
        void unpause();

        int get_ticks();

        bool is_started();
        bool is_paused();
    private:

        int start_ticks;
        int paused_ticks;
        bool paused;
        bool started;

};

#endif
