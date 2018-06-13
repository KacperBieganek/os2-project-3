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
        std::unique_lock<std::mutex> words_lock(words_mutex);
        std::unique_lock<std::mutex> encrypted_words_lock(encrypted_words_mutex);
        if((!word_generator_running && words.empty()) &&
           (!encrypter_running && encrypted_words.empty()))
        {
            words_lock.unlock();
            encrypted_words_lock.unlock();
            running = false;
        } else
        {
            words_lock.unlock();
            encrypted_words_lock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}