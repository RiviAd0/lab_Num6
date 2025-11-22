#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
using namespace std;

string chooseWord(const vector<string>& words);
void updateState(const string& word, vector<char>& guessedState, char guess);
bool isWordGuessed(const vector<char>& guessedState);

#endif // GAME_H