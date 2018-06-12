//
// Created by kacper on 09.06.18.
//

#ifndef CIPHER_WORDGENERATOR_HPP
#define CIPHER_WORDGENERATOR_HPP

#include <string>
#include <atomic>
#include <vector>
#include <fstream>

class WordGenerator
{
public:
    WordGenerator(std::vector<std::string> &words, std::atomic<bool> &running) :
            running(running),
            words(words) {};

    void run();

private:
    std::atomic<bool> &running;
    std::vector<std::string> &words;

};

#endif //CIPHER_WORDGENERATOR_HPP
