//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_TIMECOUNTER_HPP
#define CIPHER_TIMECOUNTER_HPP

#include <atomic>

class TimeCounter
{
public:
    TimeCounter(std::atomic<int> &time_passed, std::atomic<bool> &running) :
            time_passed(time_passed),
            running(running) {};

    void run();

private:
    std::atomic<int> time_passed;
    std::atomic<bool> running;
};

#endif //CIPHER_TIMECOUNTER_HPP
