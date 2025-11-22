#include "game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

string chooseWord(const vector<string>& words) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    int index = rand() % words.size();
    return words[index];
}

void updateState(const string& word, vector<char>& guessedState, char guess) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            guessedState[i] = guess;
        }
    }
}

bool isWordGuessed(const vector<char>& guessedState) {
    for (char c : guessedState) {
        if (c == '_') return false;
    }
    return true;
}