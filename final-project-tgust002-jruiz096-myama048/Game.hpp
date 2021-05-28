#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "MoveInterface.hpp"
#include "sideMove.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include "Piece.hpp"

//class Piece;

class Game {
    protected:
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::string> player_name;
	std::vector<Piece*> pieces;
	std::vector<bool> player_status;

    public:
	Game();
	virtual ~Game(){
		board.clear();
		player_name.clear();
		player_status.clear();
		pieces.clear();
	}
	virtual void play_game() = 0;
	void print_board();
	virtual bool check_win() = 0;
	virtual bool move_piece(int, int, int, int) = 0;
	virtual void player_turn(int) = 0;

	// functions for testing
	void set_piece_status_false(int i, int j) {
		pieces.at(board.at(i).at(j).second)->setStatus(false);
	}
	std::string check_board_contents(int i, int j) {
		return pieces.at(board.at(i).at(j).second)->getName();
	}
};

#endif
