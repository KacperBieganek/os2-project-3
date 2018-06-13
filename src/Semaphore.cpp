//
// Created by kacper on 08.06.18.
//

#include "Semaphore.hpp"

std::mutex Semaphore::mx;
std::condition_variable Semaphore::cv;
std::atomic<int> Semaphore::counter;

void Semaphore::notify()
{
    ++counter;
    cv.notify_all();
}

void Semaphore::wait()
{
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [] { return counter != 0; });
    --counter;
}

void Semaphore::lock()
{
    mx.lock();
}

void Semaphore::unlock()
{
    mx.unlock();
}
