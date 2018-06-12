//
// Created by kacper on 09.06.18.
//

#ifndef CIPHER_WORDGENERATOR_HPP
#define CIPHER_WORDGENERATOR_HPP

#include <string>
#include <atomic>
#include <vector>
#include <fstream>
#include <mutex>
#include <condition_variable>

class WordGenerator
{
public:
    WordGenerator(std::vector<std::string> &words, std::atomic<bool> &app_running,
                  std::atomic<bool> &word_generator_running, std::mutex &words_mutex,
                  std::condition_variable &words_cv) :
            app_running(app_running),
            word_generator_running(word_generator_running),
            words(words),
            words_mutex(words_mutex),
            words_cv(words_cv) {};

    void run();

private:
    std::atomic<bool> &app_running;
    std::atomic<bool> &word_generator_running;
    std::vector<std::string> &words;
    std::mutex &words_mutex;
    std::condition_variable &words_cv;

};

#endif //CIPHER_WORDGENERATOR_HPP
