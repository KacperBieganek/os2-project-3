//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_NUMBERGENERATOR_HPP
#define CIPHER_NUMBERGENERATOR_HPP

#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <condition_variable>

class NumberGenerator
{
public:
    NumberGenerator(std::atomic<bool> &app_running, std::vector<uint8_t> &random_numbers, std::mutex &number_mutex,
                    std::condition_variable &number_cv) :
            app_running(app_running),
            random_numbers(random_numbers),
            number_mutex(number_mutex),
            number_cv(number_cv) {};

    void run();

private:
    std::vector<uint8_t> &random_numbers;
    std::atomic<bool> &app_running;
    std::mutex &number_mutex;
    std::condition_variable &number_cv;
};

#endif //CIPHER_NUMBERGENERATOR_HPP