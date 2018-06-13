//
// Created by kacper on 08.06.18.
//

#include <Scrambler.hpp>
#include <iostream>

void Scrambler::run()
{
    while(app_running && (!words.empty() || word_generator_running))
    {
        auto word = obtain_word();
        auto key = obtain_key();
        auto encrypted_word = encrypt(word, key);
        {
            std::lock_guard<std::mutex> lock(encoded_words_mutex);
            encoded_words.push_back(encrypted_word);
        }
        encoded_words_cv.notify_one();
    }
    encrypter_running = false;
}

std::string Scrambler::obtain_word()
{
    std::unique_lock<std::mutex> lock(words_mutex);
    if(word_generator_running && words.empty())
        words_cv.wait(lock, [this] { return !words.empty(); });
    auto word = words.back();
    words.pop_back();
    lock.unlock();
    return word;
}

uint8_t Scrambler::obtain_key()
{
    std::unique_lock<std::mutex> lock(number_mutex);
    number_cv.wait(lock, [this] { return !random_numbers.empty(); });
    auto key = random_numbers.back();
    random_numbers.pop_back();
    lock.unlock();
    return key;
}

std::string Scrambler::encrypt(std::string word, uint8_t key)
{
    auto len = word.length();
    for(auto i = 0; i < len; i++)
    {
        auto temp = static_cast<unsigned char>(word[i] + key);
        (temp <= 'z' && temp >= 'a') ? (word[i] = temp) : (word[i] = static_cast<unsigned char>(temp - 26));
    }
    return word;
}