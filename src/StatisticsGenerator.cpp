//
// Created by kacper on 13.06.18.
//

#include "StatisticsGenerator.hpp"
#include <thread>
#include <chrono>

void StatisticsGenerator::run()
{
    while(app_running)
    {
        correct_percent = static_cast<double>(correct_decoding / number_of_operations);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}