#ifndef __CHESS_HPP__
#define __CHESS_HPP__

#include "Game.hpp"
#include <vector>
#include <string>
#include <utility>

class Game;

class Chess : public Game {
	protected:
		
	public:
		Chess(std::vector<std::string> names);
		void play_game();
		void get_input(int& sx, int& sy, int& dx, int& dy);
		void fill_empty_space();
		void create_player1_pieces();
		void create_player2_pieces();
		void populate_board();
		void activate_players();

		// make sure to move these back to private, only here for testing
		bool check_win();
		void player_turn(int);
		bool move_piece(int, int, int, int);
};

#endif
