//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SIMULATION_HPP
#define CIPHER_SIMULATION_HPP

#include <atomic>
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <thread>

class Simulation
{
public:
    Simulation();

    ~Simulation();

    void init_ncurses();

    void init_threads();

private:
    std::atomic<bool> app_running{true};
    std::atomic<bool> word_generator_running{true};
    std::atomic<bool> encrypters_running{true};
    std::atomic<size_t> time_passed{0};
    std::atomic<size_t> correct_decoding{0};
    std::atomic<size_t> number_of_operations{0};
    std::atomic<double> correct_decode_percent{0.0};

    std::vector<uint8_t> random_numbers;
    std::vector<std::string> words;
    std::vector<std::string> encrypted_words;
    std::vector<std::string> decrypted_words;
    std::vector<std::thread> threads;
    std::vector<std::string> list_of_words;

    std::mutex words_mutex;
    std::mutex number_mutex;
    std::mutex encrypted_words_mutex;
    std::mutex decrypted_words_mutex;
    std::mutex list_of_words_mutex;

    std::condition_variable words_cv;
    std::condition_variable number_cv;
    std::condition_variable encrypted_words_cv;
};

#endif //CIPHER_SIMULATION_HPP
