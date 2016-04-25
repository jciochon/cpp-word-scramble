#include "scrambler.hpp"


Scrambler::Scrambler()
{
    DICT_PATH = "/usr/share/dict/words";

    seed = chrono::system_clock::now().time_since_epoch().count();
    rand_engine.seed(seed);

    words = getWordsFromFile();
}


vector<string> Scrambler::getWordsFromFile()
{
    vector<string> words;
    ifstream infile(DICT_PATH);
    string line;

    // grab the whole file into a vector
    while(infile >> line)  {
        file_words.push_back(line);
    }

    // shuffle it to simulate randomness
    shuffle(file_words.begin(), file_words.end(), rand_engine);
    for (auto i = 0; i < 50; ++i) {
        words.push_back(file_words[i]);
    }

    return words;
}


void Scrambler::printWords()
{
    // use STL copy to copy the vector onto cout
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    cout << endl << endl;
}


string Scrambler::getRandomWord()
{
    shuffle(words.begin(), words.end(), rand_engine);
    return words[0];
}

void Scrambler::scramble()
{
    string current_word = getRandomWord();
    vector<char> letters;

    for(auto i = 0; i < current_word.length(); i++) {
        letters.push_back(current_word[i]);
    }

    cout << "Current word: " << current_word << endl;

    shuffle(letters.begin(), letters.end(), rand_engine);
    cout << "Shuffled: ";
    copy(letters.begin(), letters.end(), ostream_iterator<char>(cout, ""));
    cout << endl;

    return;
}


