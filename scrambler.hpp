#ifndef SCRAMBLE_H
#define SCRAMBLE_H

// standard imports
#include <String>
#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>

// other imports


using namespace std;


class Scrambler
{
    string DICT_PATH;
    vector<string> file_words;
    vector<string> words;
    default_random_engine rand_engine;
    unsigned seed;

private:
    vector<string> getWordsFromFile();
    void printWords();

public:
    Scrambler();
    string getRandomWord();
    void scramble();
};

#endif