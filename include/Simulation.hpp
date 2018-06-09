//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SIMULATION_HPP
#define CIPHER_SIMULATION_HPP

#include <atomic>
#include <string>

class Simulation
{
public:
private:
    std::atomic<int> time{0};
    std::atomic<bool> running{true};
    std::vector<int> random_ints;
    std::vector<std::string> words;
    std::vector<std::string> scrambled_words;
};

#endif //CIPHER_SIMULATION_HPP
