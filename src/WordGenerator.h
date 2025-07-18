#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

#include <string>
#include <vector>
using namespace std;

class WordGenerator{
    public:
        WordGenerator(const string& filepath = "");
        vector<string> getWordList(int count);
        string getSentence(int count);

    private:
        vector<string> wordPool;
        bool loadFromFile(const string& filepath);
        void loadDefaultWords();
};

#endif
