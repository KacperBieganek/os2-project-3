//
// Created by kacper on 09.06.18.
//

#include <iostream>
#include "WordGenerator.hpp"

void WordGenerator::run()
{
    std::ifstream stream{"words.txt", std::ios::in};
    std::string word;
    if(stream)
    {
        while(!stream.eof() && app_running)
        {
            std::getline(stream, word);
            {
                std::unique_lock<std::mutex> lock(words_mutex); //lock
                words.push_back(word);

            } //unlock
            words_cv.notify_all();
        }
        stream.close();
    } else
    {
        std::cerr << "Failed to open words.txt" << std::endl;
    }
}