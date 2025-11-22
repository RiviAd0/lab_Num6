#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    vector<string> words = { "game", "code", "question", "modification", "end" };
    string word = chooseWord(words);
    vector<char> guessedState(word.length(), '_');

    const int maxErrors = 6;
    int errors = 0;

    cout << "Добро пожаловать в игру 'Виселица'!\n";
    cout << "Угадайте слово (ENG)\n";

    while (errors < maxErrors) {
        cout << "\nТекущее состояние слова: ";
        for (char c : guessedState) {
            cout << c << ' ';
        }
        cout << "\nВведите букву: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        // Проверка, есть ли уже такая буква
        bool alreadyGuessed = false;
        for (char c : guessedState) {
            if (c == guess) {
                alreadyGuessed = true;
                break;
            }
        }
        if (alreadyGuessed) {
            cout << "Эта буква уже угадана.\n";
            continue;
        }
        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessedState[i] = guess;
                found = true;
            }
        }
        if (found) {
            cout << "Правильно!\n";
        }
        else {
            errors++;
            cout << "Ошибка! Осталось попыток: " << maxErrors - errors << "\n";
        }
        if (isWordGuessed(guessedState)) {
            cout << "Поздравляем! Вы угадали слово: " << word << "\n";
            break;
        }
    }
    if (errors >= maxErrors) {
        cout << "Вы проиграли! Загаданное слово было: " << word << "\n";
    }

    return 0;
}