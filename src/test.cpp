#include <ncurses.h>
#include "WordGenerator.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <numeric> 
#include <chrono>
#include <cmath>


void keyboard(int ch, int start_row, int start_col, int color=3) {
   // setlocale(LC_ALL, "");
   // const char* rows[] = {
   //     R"(  `  1  2  3  4  5  6  7  8  9  0  -  =  Back )",
   //     R"(  Tab   Q  W  E  R  T  Y  U  I  O  P  [  ]  \  )",
   //     R"(  Caps   A  S  D  F  G  H  J  K  L  ;  ' Enter )",
   //     R"(  Shift    Z  X  C  V  B  N  M  ,  .  / Shift )",
   //     R"(        Ctrl  Alt        Space       Alt Ctrl )"
   // };

   // int num_rows = sizeof(rows) / sizeof(rows[0]);

   // mvprintw(start_row - 1, start_col, "+--------------------------------------------------+");
   // mvprintw(start_row, start_col, rows[0]);
   // mvprintw(start_row+1, start_col, rows[1]);
   // mvprintw(start_row+2, start_col, rows[2]);
   // mvprintw(start_row+3, start_col, rows[3]);
   // mvprintw(start_row+4, start_col, rows[4]);
   // mvprintw(start_row+5 + num_rows, start_col, "+--------------------------------------------------+");

    const char* rows[] = {
        "|        `  1  2  3  4  5  6  7  8  9  0  -  =  Back       |",
        "|      Tab   Q  W  E  R  T  Y  U  I  O  P  [  ]  \\         |",
        "|      Caps   A  S  D  F  G  H  J  K  L  ;  '  Enter       |",
        "|      Shift   Z  X  C  V  B  N  M  ,  .  /   Shift        |",
        "|          Ctrl  Alt     Spacebar     Alt  Ctrl            |"
       
       
       


// "  _   _   _   _   _   _   _   _   _   _   _   _ " ,
//" / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " ,
//"( 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = )",
//" \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/", 
// "  _   _   _   _   _   _   _   _   _   _   _   _ " ,
//" / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " ,
//"( Q | W | E | R | T | Y | U | I | O | P | [ | ] )",
//" \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" ,
// "  _   _   _   _   _   _   _   _   _   _   _   _ " ,
//" / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " ,
//"( A | S | D | F | G | H | J | K | L | ; | ' | ↵ | )",
//" \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" ,
// "  _   _   _   _   _   _   _   _   _   _   _   _ " ,
//" / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " ,
//"( 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = )",
//" \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" 
    };

    int num_rows = sizeof(rows) / sizeof(rows[0]);

    mvprintw(start_row - 1, start_col, "+----------------------------------------------------------+");
    for (int i = 0; i < num_rows; ++i) {
        //for(int j=0; j<strlen(rows[i]);j++){
        //    if(rows[i][j] == ch){
        //        attron(COLOR_PAIR(1));
        //        for(int k=0;k<3;k++){
        //            mvaddch(start_row+i, start_col+j+k, rows[i][j+k]);
        //        }
        //        attroff(COLOR_PAIR(1));
        //    }
        //    else{
        //        mvaddch(start_row + i, start_col +j, rows[i][j]);
        //    }
        //}
        mvprintw(start_row+i, start_col, "%s" ,  rows[i]);
    }
    mvprintw(start_row + num_rows, start_col, "+----------------------------------------------------------+");
    
    int y, x;
    int size=0;
    
    switch(ch){
        case 96:            // char '
        case 126:           //  char ~
            x=8;
            y=0;
            size=1;
            break;
        case 49:            // char 1
        case 33:            // char !
            x=11;
            y=0;
            size=1;
            break;
        case 50:            //char 2
        case 64:            //char @
            x=14;
            y=0;
            size=1;
            break;
        case 51:            //char 3
        case 35:            //char #
            x=17;
            y=0;
            size=1;
            break;
        case 52:            //char 4 & $
        case 36:            
            x=20;
            y=0;
            size=1;
            break;
        case 53:
        case 37:
            x=23;
            y=0;
            size=1;
            break;
        case 54:
        case 94:
            x=26;
            y=0;
            size=1;
            break;
        case 55:
            x=29;
            y=0;
            size=1;
            break;
        case 56:
            x=32;
            y=0;
            size=1;
            break;
        case 57:
            x=35;
            y=0;
            size=1;
            break;
        case 48:
            x=38;
            y=0;
            size=1;
            break;
        case 45:
        case 95:
            x=41;
            y=0;
            size=1;
            break;
        case 61:
        case 43:
            x=44;
            y=0;
            size=1;
            break;
        case 127:
            x=47;
            y=0;
            size=2;
            break;
       case 65:
       case 97:
            x=13;
            y=2;
            size=1;
            break;

       case 66:
       case 98:
            x=26;
            y=3;
            size=1;
            break;

       case 67:
       case 99:
            x=20;
            y=3;
            size=1;
            break;

       case 68:
       case 100:
            x=19;
            y=2;
            size=1;
            break;

       case 69:
       case 101:
            x=18;
            y=1;
            size=1;
            break;

       case 70:
       case 102:
            x=22;
            y=2;
            size=1;
            break;

       case 71:
       case 103:
            x=25;
            y=2;
            size=1;
            break;

       case 72:
       case 104:
            x=28;
            y=2;
            size=1;
            break;

       case 73:
       case 105:
            x=33;
            y=1;
            size=1;
            break;

       case 74:
       case 106:
            x=31;
            y=2;
            size=1;
            break;

       case 75:
       case 107:
            x=34;
            y=2;
            size=1;
            break;

       case 76:
       case 108:
            x=37;
            y=2;
            size=1;
            break;

       case 77:
       case 109:
            x=32;
            y=3;
            size=1;
            break;

       case 78:
       case 110:
            x=29;
            y=3;
            size=1;
            break;

       case 79:
       case 111:
            x=36;
            y=1;
            size=1;
            break;

       case 80:
       case 112:
            x=39;
            y=1;
            size=1;
            break;

       case 81:
       case 113:
            x=12;
            y=1;
            size=1;
            break;

       case 82:
       case 114:
            x=21;
            y=1;
            size=1;
            break;

       case 83:
       case 115:
            x=16;
            y=2;
            size=1;
            break;

       case 84:
       case 116:
            x=24;
            y=1;
            size=1;
            break;

       case 85:
       case 117:
            x=30;
            y=1;
            size=1;
            break;

       case 86:
       case 118:
            x=23;
            y=3;
            size=1;
            break;

       case 87:
       case 119:
            x=15;
            y=1;
            size=1;
            break;

       case 88:
       case 120:
            x=17;
            y=3;
            size=1;
            break;

       case 89:
       case 121:
            x=27;
            y=1;
            size=1;
            break;

       case 90:
       case 122:
            x=14;
            y=3;
            size=1;
            break;
        case 9:
            x=6;
            y=1;
            break;
        case 10:
            x=46;
            y=2;
            break;
        case 32:
            x=22;
            y=4;
            break;
        default:
            x=0;
            y=0;
    }

    attron(COLOR_PAIR(color));
    //for(int i=1;i<size;i++) mvprintw(start_row+y, start_col+x+i, " ");
    
    if(ch==9) mvprintw(start_row+y, start_col+x, " TAB ");
    else if(ch==10) mvprintw(start_row+y, start_col+x, " Enter ");
    else if(ch==127) mvprintw(start_row+y, start_col+x, " Back ");
    else if(ch==32) mvprintw(start_row+y, start_col+x, "   SPACEBAR   ");
    else mvprintw(start_row+y, start_col+x, " %c ", ch);
    //for(int i=1;i<size;i++) mvprintw(start_row+y, start_col+size+x+i, " ");
    attroff(COLOR_PAIR(color));



    move(start_row, start_col+5);
    refresh();


}




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

    init_pair(5, COLOR_WHITE, COLOR_GREEN);
    init_pair(6, COLOR_WHITE, COLOR_RED);

    bkgd(COLOR_PAIR(3));
    attron(COLOR_PAIR(1)); 
    mvprintw(0, 0, "%s" , title);
    mvprintw(6, 3, "Raw Words Per Minute :");
    mvprintw(7, 3, "Words Per Minute :");

    mvprintw(8, 3, "Time Elapsed(sec) :");
    attroff(COLOR_PAIR(1));
    

    int correct =0;
    int ch=0;
    while(correct<sentence.size() && ch!=27){
        
        if(valid.size()) keyboard(ch, (maxrow / 2) + 7, (maxcol / 3), (valid.back()?5:6) );
        else keyboard(ch, (maxrow / 2) + 7, (maxcol / 3));


        if(valid.size()){ 
            auto end = chrono::high_resolution_clock::now(); 
            time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - begin).count()/1000;
            WPM = std::accumulate(valid.begin(), valid.end(), 0)/5;
            mvprintw(6, 30, "%d", (int)floor(((valid.size()/5.0)/time_elapsed)*60));
            mvprintw(7, 30, "%d", (int)floor(((WPM/time_elapsed)*60)));
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


