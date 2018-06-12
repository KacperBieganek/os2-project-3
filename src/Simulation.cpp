//
// Created by kacper on 08.06.18.
//

#include "Simulation.hpp"
#include "Ncurses.hpp"
#include "Scrambler.hpp"
#include "Descrambler.hpp"
#include "TimeCounter.hpp"
#include "NumberGenerator.hpp"
#include "WordGenerator.hpp"
#include <thread>

Simulation::Simulation()
{
    init_ncurses();
    init_threads();
}

Simulation::~Simulation()
{
    for(auto &thread : threads)
        thread.join();
    words.clear();
    encrypted_words.clear();
    encryption_map.clear();
    decryption_map.clear();
    random_numbers.clear();
}

void Simulation::init_ncurses() {}

void Simulation::init_threads()
{
    threads.push_back(std::thread{&NumberGenerator::run, NumberGenerator{running, random_numbers}});
    threads.push_back(
            std::thread{&WordGenerator::run, WordGenerator{words, running}});
}