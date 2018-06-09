//
// Created by kacper on 08.06.18.
//

#include <thread>
#include <chrono>
#include "TimeCounter.hpp"

void TimeCounter::run()
{
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++time_passed;
    }
}