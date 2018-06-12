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
        while(!stream.eof() && running)
        {
            std::getline(stream, word);
            //lock mutex
            words.push_back(word);
            //unlock
            std::cout << word << std::endl;
        }
    } else
    {
        std::cerr << "Failed to open words.txt" << std::endl;
    }
}