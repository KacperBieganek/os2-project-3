//
// Created by kacper on 08.06.18.
//

#include "Terminator.hpp"
#include "Simulation.hpp"
#include "Ncurses.hpp"
#include "Scrambler.hpp"
#include "Descrambler.hpp"
#include "TimeCounter.hpp"
#include "NumberGenerator.hpp"
#include "WordGenerator.hpp"

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
    threads.push_back(
            std::thread{&NumberGenerator::run, NumberGenerator{app_running, random_numbers, number_mutex, number_cv}});
    threads.push_back(
            std::thread{&WordGenerator::run,
                        WordGenerator{words, app_running, word_generator_running, words_mutex, words_cv}});
    threads.push_back(std::thread(&TimeCounter::run, TimeCounter{time_passed, app_running}));
    threads.push_back(std::thread(&Scrambler::run,
                                  Scrambler{app_running, word_generator_running, encrypters_running, random_numbers,
                                            words, encrypted_words,
                                            encryption_map, decryption_map, number_mutex, words_mutex,
                                            encrypted_words_mutex, encryption_map_mutex, decryption_map_mutex,
                                            number_cv, words_cv, encrypted_words_cv}));
    threads.push_back(std::thread(&Terminator::run,
                                  Terminator{app_running, word_generator_running, encrypters_running, words,
                                             encrypted_words}));
}