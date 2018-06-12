//
// Created by kacper on 08.06.18.
//

#ifndef CIPHER_SCRAMBLER_HPP
#define CIPHER_SCRAMBLER_HPP

class Scrambler
{
public:
    void run();

private:
    std::atomic<bool> &running;
    std::vector<std::string> &words;
    std::vector<std::string> &encoded_words;
};

#endif //CIPHER_SCRAMBLER_HPP
