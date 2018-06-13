//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_DESCRAMBLER_HPP
#define CIPHER_DESCRAMBLER_HPP

#include <vector>
#include <atomic>
#include <string>
#include <mutex>
#include <condition_variable>

class Descrambler
{
public:
    Descrambler(std::atomic<bool> &app_running, std::atomic<bool> &encrypter_running,
                std::vector<uint8_t> &random_numbers, std::vector<std::string> &decrypted_words,
                std::vector<std::string> &encrypted_words,
                std::mutex &number_mutex,
                std::mutex &decrypted_words_mutex, std::mutex &encrypted_words_mutex,
                std::condition_variable &number_cv,
                std::condition_variable &encrypted_words_cv, std::vector<std::string> &list_of_words,
                std::mutex &list_of_words_mutex, std::atomic<size_t> &number_of_operations,
                std::atomic<size_t> &correct_decoding) :
            app_running(app_running),
            encrypter_running(encrypter_running),
            random_numbers(random_numbers),
            decrypted_words(decrypted_words),
            encrypted_words(encrypted_words),
            number_mutex(number_mutex),
            decrypted_words_mutex(decrypted_words_mutex),
            encrypted_words_mutex(encrypted_words_mutex),
            number_cv(number_cv),
            encrypted_words_cv(encrypted_words_cv),
            list_of_words(list_of_words),
            list_of_words_mutex(list_of_words_mutex),
            number_of_operations(number_of_operations),
            correct_decoding(correct_decoding) {};

    void run();

private:

    std::string decrypt(std::string word);

    std::string obtain_word();

    uint8_t obtain_key();

    bool validate(std::string word);

    std::atomic<bool> &app_running;
    std::atomic<bool> &encrypter_running;
    std::atomic<size_t> &number_of_operations;
    std::atomic<size_t> &correct_decoding;

    std::vector<uint8_t> &random_numbers;
    std::vector<std::string> &decrypted_words;
    std::vector<std::string> &encrypted_words;
    std::vector<std::string> &list_of_words;

    std::mutex &number_mutex;
    std::mutex &encrypted_words_mutex;
    std::mutex &decrypted_words_mutex;
    std::mutex &list_of_words_mutex;

    std::condition_variable &number_cv;
    std::condition_variable &encrypted_words_cv;
};

#endif //CIPHER_DESCRAMBLER_HPP
