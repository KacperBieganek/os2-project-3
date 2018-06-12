//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SCRAMBLER_HPP
#define CIPHER_SCRAMBLER_HPP

#include <vector>
#include <string>
#include <mutex>
#include <atomic>
#include <condition_variable>

class Scrambler
{
public:

    Scrambler(std::atomic<bool> &app_running, std::vector<std::string> &words, std::vector<std::string> &encoded_words,
              std::mutex &words_mutex, std::mutex &encoded_words_mutex, std::condition_variable &words_cv,
              std::condition_variable &encoded_words_cv) :
            app_running(app_running),
            words(words),
            encoded_words(encoded_words),
            words_mutex(words_mutex),
            encoded_words_mutex(encoded_words_mutex),
            words_cv(words_cv),
            encoded_words_cv(encoded_words_cv) {};

    void run();

private:
    std::atomic<bool> &app_running;
    std::vector<std::string> &words;
    std::vector<std::string> &encoded_words;

    std::mutex &words_mutex;
    std::mutex &encoded_words_mutex;

    std::condition_variable &words_cv;
    std::condition_variable &encoded_words_cv;
};

#endif //CIPHER_SCRAMBLER_HPP
