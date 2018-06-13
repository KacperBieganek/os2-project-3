//
// Created by kacper on 13.06.18.
//

#ifndef CIPHER_STATISTICSGENERATOR_HPP
#define CIPHER_STATISTICSGENERATOR_HPP

#include <atomic>

class StatisticsGenerator
{
public:
    StatisticsGenerator(std::atomic<size_t> &number_of_operations, std::atomic<size_t> &correct_decoding,
                        std::atomic<double> &correct_percent, std::atomic<bool> &app_running) :
            number_of_operations(number_of_operations),
            correct_decoding(correct_decoding),
            correct_percent(correct_percent),
            app_running(app_running) {};

    void run();

private:
    std::atomic<bool> &app_running;
    std::atomic<size_t> &number_of_operations;
    std::atomic<size_t> &correct_decoding;
    std::atomic<double> &correct_percent;

};

#endif //CIPHER_STATISTICSGENERATOR_HPP
