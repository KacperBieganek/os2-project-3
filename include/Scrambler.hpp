//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SCRAMBLER_HPP
#define CIPHER_SCRAMBLER_HPP

#include <vector>
#include <string>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <unordered_map>

class Scrambler
{
public:

    Scrambler(std::atomic<bool> &app_running, std::atomic<bool> &word_generator_running,
              std::atomic<bool> &encrypter_running,
              std::vector<uint8_t> &random_numbers, std::vector<std::string> &words,
              std::vector<std::string> &encoded_words, std::unordered_map<std::string, std::string> &encryption_map,
              std::unordered_map<std::string, std::string> &decryption_map, std::mutex &number_mutex,
              std::mutex &words_mutex, std::mutex &encoded_words_mutex, std::mutex &encryption_map_mutex,
              std::mutex &decryption_map_mutex, std::condition_variable &number_cv,
              std::condition_variable &words_cv,
              std::condition_variable &encoded_words_cv) :
            app_running(app_running),
            word_generator_running(word_generator_running),
            encrypter_running(encrypter_running),
            random_numbers(random_numbers),
            words(words),
            number_mutex(number_mutex),
            encoded_words(encoded_words),
            encryption_map(encryption_map),
            decryption_map(decryption_map),
            words_mutex(words_mutex),
            encoded_words_mutex(encoded_words_mutex),
            encryption_map_mutex(encryption_map_mutex),
            decryption_map_mutex(decryption_map_mutex),
            number_cv(number_cv),
            words_cv(words_cv),
            encoded_words_cv(encoded_words_cv) {};

    void run();

private:

    std::string encrypt(std::string word, uint8_t key);

    std::string obtain_word();

    uint8_t obtain_key();

    std::atomic<bool> &app_running;
    std::atomic<bool> &word_generator_running;
    std::atomic<bool> &encrypter_running;

    std::vector<uint8_t> &random_numbers;
    std::vector<std::string> &words;
    std::vector<std::string> &encoded_words;
    std::unordered_map<std::string, std::string> encryption_map;
    std::unordered_map<std::string, std::string> decryption_map;

    std::mutex &number_mutex;
    std::mutex &words_mutex;
    std::mutex &encoded_words_mutex;
    std::mutex &encryption_map_mutex;
    std::mutex &decryption_map_mutex;

    std::condition_variable &number_cv;
    std::condition_variable &words_cv;
    std::condition_variable &encoded_words_cv;
};

#endif //CIPHER_SCRAMBLER_HPP
