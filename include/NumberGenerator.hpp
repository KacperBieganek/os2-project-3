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
    NumberGenerator(std::atomic<bool> &running, std::vector<unsigned char> &random_numbers) :
            running(running),
            random_numbers(random_numbers) {};

    void run();

private:
    std::vector<unsigned char> random_numbers;
    std::atomic<bool> running;
};

#endif //CIPHER_NUMBERGENERATOR_HPP