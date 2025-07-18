// src/main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <ncurses.h>
#include "WordGenerator.h"
#include <chrono>




int main() {
    WordGenerator wg = WordGenerator("data/words.txt");
    std::string word = wg.getSentence(10);

    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    int len = word.size();
    std::string st = "";
    int i = 0;
    int crt = 0;
    int completed_words = 0; 
    auto begin = chrono::high_resolution_clock::now();

    printw("%s", word.c_str());
    while (i < len) {
        int ch = getch();
        if(ch == (int)' ') completed_words++;
        if(ch == '\n') break;
        if(ch == 27) break;
        if(ch == KEY_BACKSPACE || ch == 127){ 
            if(st.back() == word[crt]) crt--;
            st.pop_back();
            i=i-2;
        }
        else{ 
            st += static_cast<char>(ch);
            if(word[crt+1]==ch) crt++;
        }
        clear();


        for (int j = 0; j < st.size(); j++) {
            if (j < len && st[j] == word[j]) {
                attron(COLOR_PAIR(1));
                printw("%c", st[j]);
                attroff(COLOR_PAIR(1));
            } else if (j < len) {
                attron(COLOR_PAIR(2));
                printw("%c", st[j]);
                attroff(COLOR_PAIR(2));
            }
        }


        if (crt < len) {
            printw("%s", word.substr(i+1, len-i).c_str());
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(end - begin).count();
        string wpm = to_string(completed_words/((duration/60)+1));
        string time_elapsed = to_string(duration);

        mvaddstr(10, 30, "Words Per second :");
        mvaddstr(10, 60, wpm.c_str());
        mvaddstr(11, 30, "Time Elapsed :");
        mvaddstr(11, 60, time_elapsed.c_str());
        refresh();
        i++;
    }

    endwin();
    return 0;
}

