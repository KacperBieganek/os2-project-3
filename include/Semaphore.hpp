//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SEMAPHORE_HPP
#define CIPHER_SEMAPHORE_HPP

#include <mutex>
#include <condition_variable>
#include <atomic>

class Semaphore
{
public:
    Semaphore() = delete;

    Semaphore(const Semaphore &) = delete;

    static void notify();

    static void wait();

    static void lock();

    static void unlock();

    static std::mutex &get_mutex();

    static std::condition_variable &get_condition_variable();

private:
    static std::mutex mx;
    static std::condition_variable cv;
    static std::atomic<int> counter;
};

#endif //CIPHER_SEMAPHORE_HPP
