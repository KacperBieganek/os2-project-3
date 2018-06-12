//
// Created by kacper on 13.06.18.
//

#include "Terminator.hpp"
#include <chrono>
#include <thread>
#include <iostream>

void Terminator::run()
{
    while(running)
    {
        if((!word_generator_running && words.empty()) && (!encrypter_running && encrypted_words.empty()))
            running = false;
        else
            std::this_thread::sleep_for(std::chrono::seconds(1));

    }
    std::cout << "TERMINATOR DED" << std::endl;
}