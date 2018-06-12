//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_TIMECOUNTER_HPP
#define CIPHER_TIMECOUNTER_HPP

#include <atomic>

class TimeCounter
{
public:
    TimeCounter(std::atomic<size_t> &time_passed, std::atomic<bool> &app_running) :
            time_passed(time_passed),
            app_running(app_running) {};

    void run();

private:
    std::atomic<size_t> &time_passed;
    std::atomic<bool> &app_running;
};

#endif //CIPHER_TIMECOUNTER_HPP
