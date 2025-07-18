// src/main.cpp
#include <iostream>  // For std::cout (for initial debugging)
#include <fstream>   // For file operations (std::ifstream)
#include <string>    // For std::string
#include <vector>    // For std::vector
#include <random>    // For shuffling words later (good to include now)
#include <algorithm> // For std::shuffle later
#include <ncurses.h> // Include the ncurses header
#include "WordGenerator.h"


int main() {


    WordGenerator wg = WordGenerator("data/words.txt");
    std::string word = wg.getSentence(150);
    

    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    int len = word.size();
    string st = "";
    int i =0;
    int crt =0;
    while(i<len){
        while(i<st.size()){
            if(st[i]==word[i]){
                attron(COLOR_PAIR(1));       // Turn on green
                printw("%s", &st[i]);         // Print char at current position
                attroff(COLOR_PAIR(1));
                crt++;
            }
            else{
                attron(COLOR_PAIR(2));       // Turn on green
                printw("%s", &st[i]);        // Print char at current position
                attroff(COLOR_PAIR(2));
            }
            i++;
        }

        printw("%s", word.substr(crt, len-crt).c_str());
        refresh();
    }


    endwin();
    return 0;
}

