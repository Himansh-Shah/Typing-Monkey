#include <ncurses.h>
#include "WordGenerator.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

int main() {
    WordGenerator wg = WordGenerator("data/words.txt");
    std::string sentence = wg.getSentence(150) + " ";
    int maxrow, maxcol;
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
    attroff(COLOR_PAIR(1));
    

    vector<int> valid = {};
    int correct =0;
    int ch;

    while(correct<sentence.size() && ch!=27){
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
        mvprintw(maxrow /2, maxcol /2, "%s", sentence.substr(correct, maxcol/2).c_str());
        refresh();
        ch=getch();
        if(valid.size() && ch == 127){ 
                valid.pop_back();
                correct--;
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
    return 0;
}


