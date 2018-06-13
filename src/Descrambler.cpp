//
// Created by kacper on 08.06.18.
//

#include <iostream>
#include <chrono>
#include <algorithm>
#include "Descrambler.hpp"
#include <thread>

void Descrambler::run()
{
    while(app_running && (!encrypted_words.empty() || encrypter_running))
    {
        auto encrypted_word = obtain_word();
        auto decrypted_word = decrypt(encrypted_word);
        {
            std::lock_guard<std::mutex> lock(decrypted_words_mutex);
            decrypted_words.push_back(decrypted_word);
        }
    }
}

std::string Descrambler::obtain_word()
{
    std::unique_lock<std::mutex> lock(encrypted_words_mutex);
    if(encrypter_running && encrypted_words.empty())
        encrypted_words_cv.wait(lock, [this] { return !encrypted_words.empty(); });
    auto word = encrypted_words.back();
    encrypted_words.pop_back();
    lock.unlock();
    return word;
}

uint8_t Descrambler::obtain_key()
{
    std::unique_lock<std::mutex> lock(number_mutex);
    number_cv.wait(lock, [this] { return !random_numbers.empty(); });
    auto key = random_numbers.back();
    random_numbers.pop_back();
    lock.unlock();
    return key;
}

std::string Descrambler::decrypt(std::string word)
{
    auto len = word.length();
    std::string decrypted_word;
    do
    {
        decrypted_word = word;
        auto key = obtain_key();
        for(auto i = 0; i < len; i++)
        {
            auto temp = static_cast<unsigned char>(decrypted_word[i] - key);
            (temp >= 'a') ? decrypted_word[i] = temp : decrypted_word[i] = static_cast<unsigned char>(temp + 26);
        }
    } while(!validate(decrypted_word));
    return decrypted_word;
}

bool Descrambler::validate(std::string decrypted_word)
{
    std::unique_lock<std::mutex> lock(list_of_words_mutex);
    auto iterator = std::find(list_of_words.begin(), list_of_words.end(), decrypted_word);
    lock.unlock();
    return iterator != list_of_words.end();
}