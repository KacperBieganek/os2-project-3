//
// Created by kacper on 13.06.18.
//

#ifndef CIPHER_TERMINATOR_HPP
#define CIPHER_TERMINATOR_HPP

#include <vector>
#include <atomic>
#include <string>

class Terminator
{
public:
    Terminator(std::atomic<bool> &running, std::atomic<bool> &word_generator_running,
               std::atomic<bool> &encrypter_running, std::vector<std::string> &words,
               std::vector<std::string> &encrypted_words) :
            running(running),
            word_generator_running(word_generator_running),
            encrypter_running(encrypter_running),
            words(words),
            encrypted_words(encrypted_words) {};

    void run();

private:
    std::atomic<bool> &running;
    std::atomic<bool> &word_generator_running;
    std::atomic<bool> &encrypter_running;

    std::vector<std::string> &words;
    std::vector<std::string> &encrypted_words;

};

#endif //CIPHER_TERMINATOR_HPP
