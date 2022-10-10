#include <iostream>
#include "Game.cpp"


int main() {

	Game game;

	while (true) {

		std::cout << "\n\nA new game has started!\n\n";
		game.startGame();

		while (game.getStatus()) 
			game.addLetter();
		
	}

	return 0;
}
