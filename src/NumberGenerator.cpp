//
// Created by kacper on 08.06.18.
//

#include "NumberGenerator.hpp"
#include <iostream>
#include <fstream>

void NumberGenerator::run()
{
    while(running)
    {
        uint8_t random_value = 0;
        uint8_t number_of_letters = 26;
        size_t size = sizeof(random_value);
        std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
        if(urandom)
        {
            while(running)
            {
                urandom.read(reinterpret_cast<char *>(&random_value), size);
                if(urandom)
                {
                    random_value = random_value % number_of_letters;
                } else  // Reading failure
                {
                    random_value = static_cast<uint8_t>(rand() % number_of_letters);
                }
                random_numbers.push_back(random_value);
                //Semaphore::notify();
            }
            urandom.close();
        } else
        {
            std::cerr << "Failed to open /dev/urandom" << std::endl;
        }
    }
}