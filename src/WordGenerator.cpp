#include "WordGenerator.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

WordGenerator::WordGenerator(const string& filepath){
    if(!filepath.empty()){
        if(!loadFromFile(filepath)){
            cerr<< "[Warning] Failed to load word list from file. Using default word list. \n";
            loadDefaultWords();
        }
    }
    else{
        loadDefaultWords();
    }
}

bool WordGenerator :: loadFromFile(const string& filepath){
    ifstream file(filepath);
    if(!file.is_open()) return false;

    string word;

    while( getline(file, word)){
        wordPool.push_back(word);
    }

    return !wordPool.empty();
}


void WordGenerator::loadDefaultWords(){
    wordPool = {
        "apple", "banana"
    };
}


vector<string> WordGenerator::getWordList(int count){
    vector<string> selected;
    if(wordPool.empty()) return selected;

    mt19937 rng(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<int> dist(0, wordPool.size() -1);

    for(int i=0;i<count;i++){
        selected.push_back(wordPool[dist(rng)]);
    }

    return selected;
}


string WordGenerator::getSentence(int count){
    vector<string> list = getWordList(count);
    ostringstream oss;
    for(size_t i=0; i<list.size(); ++i){
        oss<<list[i];
        if(i != list.size() -1){
            oss<<" ";
        }
    }
    return oss.str();
}
