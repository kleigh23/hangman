#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
    // word list
    vector<string> words = {"school", "pokemon", "marvel","books", "disney", "dragon", "gaming"};

    // initialize randsom number generator
    srand(time(0));
    int randomIndex = rand() % words.size();
    string wordToGuess = words[randomIndex];

    // initialize game variables
    int lives = 6;
    string displayedWord(wordToGuess.size(), '_');
    vector<char> guessedLetters;

    // main game loop
    while (lives >0 && displayedWord != wordToGuess) {
            cout << "Lives: " << lives << "\n";
            cout << "Word: " << displayedWord << "\n";
            cout << "Guessed Letters: ";
            for (char letter : guessedLetters) {
                cout << letter << " ";
            }
            cout << "\n";

            char guess;
            cout << "Guess a letter: ";
            cin >> guess;
            guess = std::tolower(guess);

            bool correctGuess = false;
            for (int i = 0; i < wordToGuess.length(); i++) {
                if (wordToGuess[i] == guess) {
                    displayedWord[i] = guess;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                lives--;
                cout << "Incorrect guess." << "\n";
            }

            guessedLetters.push_back(guess);
    }

    // end game
    if (lives  == 0) {
        cout << "You Lost! The word was: " << wordToGuess << "\n";
    } else {
        cout << "You Won! The word was: " << wordToGuess << "\n";
    }

    return 0;
}