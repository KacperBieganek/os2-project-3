//
// Created by kacper on 13.06.18.
//

#ifndef CIPHER_TERMINATOR_HPP
#define CIPHER_TERMINATOR_HPP

#include <vector>
#include <atomic>
#include <string>
#include <mutex>

class Terminator
{
public:
    Terminator(std::atomic<bool> &running, std::atomic<bool> &word_generator_running,
               std::atomic<bool> &encrypter_running, std::vector<std::string> &words,
               std::vector<std::string> &encrypted_words, std::mutex &words_mutex, std::mutex &encrypted_words_mutex) :
            running(running),
            word_generator_running(word_generator_running),
            encrypter_running(encrypter_running),
            words(words),
            encrypted_words(encrypted_words),
            words_mutex(words_mutex),
            encrypted_words_mutex(encrypted_words_mutex) {};

    void run();

private:
    std::atomic<bool> &running;
    std::atomic<bool> &word_generator_running;
    std::atomic<bool> &encrypter_running;

    std::vector<std::string> &words;
    std::vector<std::string> &encrypted_words;

    std::mutex &words_mutex;
    std::mutex &encrypted_words_mutex;

};

#endif //CIPHER_TERMINATOR_HPP
