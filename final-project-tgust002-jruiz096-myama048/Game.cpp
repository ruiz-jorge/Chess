#include "Game.hpp"


Game::Game() {}
void Game::print_board() {
	// loop through outer vector
	for(int i = 0; i < 8; i++) {
		// loop through inner vector 
		if (i == 0) std::cout << "  0 1 2 3 4 5 6 7\n";
		std::cout << i << " ";
		for (int j = 0; j < 8; j++) {
			if (board.at(i).at(j).first)
				std::cout << pieces.at(board.at(i).at(j).second)->getName() << " ";
			else
				std::cout << "~" << " ";
		}
		std::cout << std::endl;
	}
}

