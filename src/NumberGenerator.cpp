//
// Created by kacper on 08.06.18.
//

#include "NumberGenerator.hpp"

void NumberGenerator::run()
{
    while(running)
    {
        unsigned char random_value = 0;
        size_t size = sizeof(random_value);
        std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
        if(urandom)
        {
            while(running)
            {
                urandom.read(reinterpret_cast<char *>(&random_value), size);
                if(urandom)
                {
                    random_value = random_value % 26;
                } else  // Reading failure
                {
                    random_value = rand() % 26;
                }
                random_numbers.push_back(random_value);
                Semaphore::notify();
            }
            urandom.close();
        } else
        {
            std::cerr << "Failed to open /dev/urandom" << std::endl;
        }
    }
}