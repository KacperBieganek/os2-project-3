//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_NCURSES_HPP
#define CIPHER_NCURSES_HPP

#include <atomic>
#include <vector>
#include <string>
#include <curses.h>

class Ncurses
{
public:

    Ncurses(std::atomic<bool> &app_running, std::atomic<size_t> &time, std::atomic<size_t> &number_of_operations,
            std::atomic<size_t> &correct_decoding, std::atomic<double> &correct_percent,
            std::vector<std::string> &decoded_words, std::mutex &decoded_words_mutex, int width, int height) :
            app_running(app_running),
            time(time),
            number_of_operations(number_of_operations),
            correct_decoding(correct_decoding),
            correct_percent(correct_percent),
            decoded_words(decoded_words),
            decoded_words_mutex(decoded_words_mutex),
            width(width),
            height(height)
    {

    };

    void run();

private:
    int width;
    int height;
    std::atomic<bool> &app_running;
    std::atomic<size_t> &time;
    std::atomic<size_t> &number_of_operations;
    std::atomic<size_t> &correct_decoding;
    std::atomic<double> &correct_percent;
    std::vector<std::string> &decoded_words;

    std::mutex &decoded_words_mutex;

    WINDOW *w_live = newwin(7, width / 2, 1, 1);
    WINDOW *w_visual = newwin(7, width / 2, 8, 1);
    WINDOW *w_recently = newwin(7, width / 2, 1, width / 2);
    WINDOW *w_success = newwin(6, width / 2, 8, width / 2);
    WINDOW *w_mode = newwin(1, 25, 14, width / 2);
    WINDOW *w_author = newwin(1, width, 16, 0);
    WINDOW *w_general = newwin(16, width, 0, 0);

//    void print_decoded_words();
//
//    void print_statistics();
};

#endif //CIPHER_NCURSES_HPP
