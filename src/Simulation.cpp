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
#include "StatisticsGenerator.hpp"
#include <curses.h>

Simulation::Simulation()
{
    list_of_words.reserve(3000);
    decrypted_words.reserve(3000);
    init_ncurses();
    init_threads();
}

Simulation::~Simulation()
{
    for(auto &thread : threads)
        thread.join();
    endwin();
    words.clear();
    encrypted_words.clear();
    list_of_words.clear();
    random_numbers.clear();
}

void Simulation::init_ncurses()
{
    initscr();
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, height, width);
    refresh();
}

void Simulation::init_threads()
{
    threads.push_back(
            std::thread{&NumberGenerator::run, NumberGenerator{app_running, random_numbers, number_mutex, number_cv}});
    threads.push_back(
            std::thread{&WordGenerator::run,
                        WordGenerator{words, list_of_words, app_running, list_of_words_mutex, word_generator_running,
                                      words_mutex, words_cv}});
    threads.push_back(std::thread(&TimeCounter::run, TimeCounter{time_passed, app_running}));
    threads.push_back(std::thread(&Terminator::run,
                                  Terminator{app_running, word_generator_running, encrypters_running, words,
                                             encrypted_words, words_mutex, encrypted_words_mutex}));
    threads.push_back(std::thread(&StatisticsGenerator::run,
                                  StatisticsGenerator{number_of_operations, correct_decoding, correct_decode_percent,
                                                      app_running}));
    for(size_t i = 0; i < 5; i++)
    {
        threads.push_back(std::thread(&Scrambler::run,
                                      Scrambler{app_running, word_generator_running, encrypters_running, random_numbers,
                                                words, encrypted_words,
                                                number_mutex, words_mutex,
                                                encrypted_words_mutex,
                                                number_cv, words_cv, encrypted_words_cv}));
    }
    for(int i = 0; i < 45; i++)
    {
        threads.push_back(std::thread(&Descrambler::run,
                                      Descrambler{app_running, encrypters_running, random_numbers, decrypted_words,
                                                  encrypted_words, number_mutex,
                                                  decrypted_words_mutex, encrypted_words_mutex, number_cv,
                                                  encrypted_words_cv, list_of_words, list_of_words_mutex,
                                                  number_of_operations, correct_decoding}));

    }
    threads.push_back(std::thread(&Ncurses::run,
                                  Ncurses{app_running, time_passed, number_of_operations, correct_decoding,
                                          correct_decode_percent,
                                          decrypted_words, decrypted_words_mutex, width, height}));
}