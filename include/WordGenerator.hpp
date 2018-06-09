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
    WordGenerator(std::fstream &file_stream, std::vector<std::string> &words, std::atomic<bool> &running) :
            running(running),
            words(words),
            file_stream(file_stream) {};

    void run();

private:
    std::ifstream file_stream;
    std::atomic<bool> running;
    std::vector<std::string> words;

};

#endif //CIPHER_WORDGENERATOR_HPP
