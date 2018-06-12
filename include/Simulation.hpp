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
    std::atomic<size_t> time{0};
    std::atomic<bool> running{true};
    std::atomic<int> number_of_operations{0};
    std::atomic<int> correct_decoding{0};
    std::atomic<double> correct_decode_percent{0.0d};

    std::vector<uint8_t> random_numbers;
    std::vector<std::string> words;
    std::vector<std::string> encrypted_words;
    std::vector<std::string> decrypted_words;
    std::vector<std::thread> threads;
    std::unordered_map<std::string, std::string> encryption_map;
    std::unordered_map<std::string, std::string> decryption_map;

    std::mutex words_mutex;
    std::mutex encrypted_words_mutex;
    std::mutex decrypted_words_mutex;
    std::mutex encryption_map_mutex;
    std::mutex decryption_map_mutex;

    std::condition_variable words_cv;
    std::condition_variable encrypted_words_cv;
    std::condition_variable decrypted_words_cv;
};

#endif //CIPHER_SIMULATION_HPP
