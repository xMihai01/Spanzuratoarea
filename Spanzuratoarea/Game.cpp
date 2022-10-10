#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

void toUpperCaseString(std::string& wordToUpper);
void toUpperCaseLetter(char& letter);

class Game {

	std::vector<std::string> wordsList;
	std::string word;
	std::string hiddenWord;
	int tries;
	bool isGameRunning;

public:

	Game() {

		std::ifstream read("words.txt");
		while (read >> word)
			wordsList.push_back(word);

		word = "";
		hiddenWord = "";
		tries = 6;

	}

	bool getStatus() {
		return this->isGameRunning;
	}

	void startGame() {

		setRandomWord();
		this->isGameRunning = true;
		this->tries = 6;

	}
	void resetGame() {
		word = "";
		hiddenWord = "";
		isGameRunning = false;
		tries = 6;
		
	}

	void addLetter() {

		showProgress();
		std::string guess;
		std::cout << "\nGuess: ";
		std::cin >> guess;

		if (guess.length() > 1 && guess == this->word) {
			std::cout << "\nCongratulations! You won!\n";
			resetGame();
			return;
		}
		else if (guess.length() > 1 && guess != this->word) {
			tries--;
			checkStatus();
			return;
		}

		toUpperCaseLetter(guess[0]);
		std::string s(1, guess[0]);

		if (this->word.find(guess[0]) != std::string::npos) {

			for (int i = 0; i < word.length(); i++) {
				if (word[i] == guess[0])
					hiddenWord[i * 2] = guess[0];
			}
		}
		else {
			tries--;
		}
		checkStatus();

	}

	void setRandomWord() {
		srand(time(NULL));
		int a = rand() % wordsList.size();
		word = wordsList[a];
		toUpperCaseString(word);
		for (unsigned int i = 0; i < word.length(); i++) {
			hiddenWord += '_';
			hiddenWord += ' ';
		}
	}

	void showProgress() {

		std::cout << this->hiddenWord << "\n" << this->tries << " tries left!\n\n";

	}

	void checkStatus() {

		if (checkWords()) {
			std::cout << "\nCongratulations! You won!\n";
			resetGame();
			return;
		}
		if (tries <= 0) {
			std::cout << "\nYou ran out of tries! You lost!\n" << "The word was: " << this->word;
			resetGame();
			return;
		}

	}

	bool checkWords() {

		bool temp = true;
		for (int i = 0; i < word.length(); i++) {

			if (word[i] != hiddenWord[i * 2])
				temp = false;

		}
		return temp;
	}
};