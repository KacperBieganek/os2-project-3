//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_NUMBERGENERATOR_HPP
#define CIPHER_NUMBERGENERATOR_HPP

#include <vector>
#include <iostream>
#include <atomic>

class NumberGenerator
{
public:
    NumberGenerator(std::atomic<bool> &running, std::vector<uint8_t> &random_numbers) :
            running(running),
            random_numbers(random_numbers) {};

    void run();

private:
    std::vector<uint8_t> &random_numbers;
    std::atomic<bool> &running;
};

#endif //CIPHER_NUMBERGENERATOR_HPP