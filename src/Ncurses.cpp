//
// Created by kacper on 08.06.18.
//

#include <chrono>
#include <thread>
#include <curses.h>
#include <mutex>
#include "Ncurses.hpp"

void Ncurses::run()
{
    while(app_running)
    {
        werase(w_live);
        werase(w_visual);
        werase(w_recently);
        werase(w_success);
        werase(w_mode);

        //mvwprintw(w_live, 1, 1, "%d decoders alive", (int) live_decoders);
        //mvwprintw(w_live, 3, 1, "%d encoders alive", (int) live_encoders);
        wrefresh(w_live);

        for(int i = 1; i < 23; i++)
        {
            int h = rand() % 7;
            for(int j = 0; j < h; j++)
            {
                wmove(w_visual, 6 - j, i);
                waddch(w_visual, (char) 219);
            }
        }

        wrefresh(w_visual);

        {
            mvwprintw(w_recently, 1, 0, "recently decoded:");
            std::unique_lock<std::mutex> lock1(decoded_words_mutex);
            if(!decoded_words.empty())
            {
                mvwprintw(w_recently, 3, 4, "%s", decoded_words.back().c_str());
                if(decoded_words.size() > 1)
                {
                    mvwprintw(w_recently, 4, 4, "%s", (decoded_words.rbegin()[1]).c_str());
                    if(decoded_words.size() > 2)
                    {
                        mvwprintw(w_recently, 5, 4, "%s", (decoded_words.rbegin()[2]).c_str());
                    }
                }
            }
        }

        wrefresh(w_recently);

        mvwprintw(w_success, 1, 0, "all decoding tries: %i", (int) number_of_operations);
        mvwprintw(w_success, 2, 0, "succesfull decodes: %i", (int) correct_decoding);
        mvwprintw(w_success, 3, 0, "success ratio: %.3f%%", (float) correct_percent * 100.0);
        mvwprintw(w_success, 4, 0, "time running: %i", (int) time);

        wrefresh(w_success);

        mvwprintw(w_mode, 0, 0, "DECODING MODE");

        wrefresh(w_mode);

        mvwprintw(w_author, 0, 0, "== KACPER BIEGANEK, 2018 - gui stolen from KRZYSZTOF BUCZAK! ==");

        wrefresh(w_author);

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}