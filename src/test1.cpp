#include <ncurses.h>
#include "WordGenerator.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <numeric> 
#include <chrono>
#include <cmath>


int main() {
    WordGenerator wg = WordGenerator("data/words.txt");
    std::string sentence = wg.getSentence(25) + " ";
    vector<int> valid = {};
    int maxrow, maxcol;
    float WPM;
    auto begin = chrono::high_resolution_clock::now();
    int time_elapsed;
    char title[] = 
R"(    
 _____ _____ _  _  _  __     _   _  _  _  _  _  ______ __
|_ _\ V / o \ || \| |/ _|   | \_/ |/ \| \| || |// __\ V /
 | | \ /|  _/ || \\ ( |_n__ | \_/ ( o ) \\ ||  (| _| \ / 
 |_| |_||_| |_||_|\_|\__/__||_| |_|\_/|_|\_||_|\\___||_|)";


    initscr();
    getmaxyx(stdscr, maxrow, maxcol);
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    bkgd(COLOR_PAIR(3));
    attron(COLOR_PAIR(1)); 
    mvprintw(0, 0, "%s" , title);
    mvprintw(6, 3, "Raw Words Per Minute :");
    mvprintw(7, 3, "Words Per Minute :");

    mvprintw(8, 3, "Time Elapsed(sec) :");
    attroff(COLOR_PAIR(1));
    

    int correct =0;
    int ch;
    while(correct<sentence.size() && ch!=27){
        if(valid.size()){ 
            auto end = chrono::high_resolution_clock::now(); 
            time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - begin).count()/1000;
            WPM = std::accumulate(valid.begin(), valid.end(), 0)/5;
            mvprintw(6, 30, "%d", (int)floor(((valid.size()/5.0)/time_elapsed)*60));
            mvprintw(7, 30, "%d", floor(((WPM/time_elapsed)*60)));
            mvprintw(8, 30, "%d", time_elapsed);
        }
        move(maxrow/2 , 0);
        clrtoeol();
        for(int i=0;i<valid.size();i++){
            if(valid[i]){ 
                attron(COLOR_PAIR(4));
                mvaddch(maxrow / 2, maxcol / 2 - valid.size() + i, sentence[i]);
                attroff(COLOR_PAIR(4));
            }
            else{
                attron(COLOR_PAIR(2));
                mvaddch(maxrow / 2, maxcol / 2 - valid.size() + i,  sentence[i]);
                attroff(COLOR_PAIR(2));
            }
        }
        mvprintw(maxrow /2, maxcol /2, "%s", sentence.substr(correct, maxcol/2 -1).c_str());
        refresh();
        ch=getch();
        if(ch == 127){ 
            if(valid.size()){    
                valid.pop_back();
                correct--;
            }
                continue;
        }
        if(ch == (int)sentence[correct]){ 
            valid.emplace_back(1);
        }
        else{
            valid.emplace_back(0);
        }
        correct++;

    }
    endwin();
    std::cout<<"Your words per minute speed was :"<< WPM<<std::endl;
    std::cout<<"Time taken :"<< time_elapsed<<std::endl;
    return 0;
}


