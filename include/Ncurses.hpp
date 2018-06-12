//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_NCURSES_HPP
#define CIPHER_NCURSES_HPP

#include <atomic>
#include <vector>
#include <string>

class Ncurses
{
public:
    void run();

private:
    std::atomic<bool> &running;
    std::atomic<unsigned int> &time;
    std::atomic<double> &correct_percent;
    std::atomic<size_t> &number_of_operations;
    std::vector<std::string> &decoded_words;

    void print_decoded_words();

    void print_statistics();
};

#endif //CIPHER_NCURSES_HPP
