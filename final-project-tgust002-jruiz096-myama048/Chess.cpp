#include "Chess.hpp"

bool Chess::check_win() {
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces.at(i)->getName() == "K" && pieces.at(i)->returnStatus() == false) {
			player_status.at(0) = false;
			return true;
		}
		if (pieces.at(i)->getName() == "k" && pieces.at(i)->returnStatus() == false) {
			player_status.at(1) = false;
			return true;
		}
	}
	return false;
}

void Chess::player_turn(int curr_player) {
	int pos_x;
	int pos_y;
	int dest_x;
	int dest_y;
	// check if player is active
	 	if (player_status.at(curr_player - 1)) {
	 		// get input from the user
	 		get_input(pos_x, pos_y, dest_x, dest_y);
	 		// check if current player is trying to move enemy piece
	 		if (board.at(pos_x).at(pos_y).first == curr_player) {
	 			// call move on piece
	 			if (!move_piece(pos_x, pos_y, dest_x, dest_y))
					std::cout << "Invalid Move!" << std::endl;
			}
			else
				std::cout << "Not Your Piece!" << std::endl; 
		}
}

bool Chess::move_piece(int sx, int sy, int dx, int dy) {
	if (sx > 8 || sy > 8 || sx < 0 || sy < 0 || dx > 8 || dy > 8 || dx < 0 || dy < 0)
		return false;
	std::string move_type;
	MoveInterface* mv = nullptr;
	if (sx == dx) {
		move_type = "Side";
		mv = new SideMove();
	}
	else if (sy == dy) {
		move_type = "Straight";
		mv = new StraightMove();
	}
	else if (abs(sx - dx) == abs(sy - dy)) {
		move_type = "Diagonal";
		mv = new DiagonalMove();
	}
	else {
		move_type = "Knight";
		mv = new KnightMove();
	}
	if (pieces.at(board.at(sx).at(sy).second)->setBehavior(mv, move_type)) {
		if (pieces.at(board.at(sx).at(sy).second)->move(board, pieces, sx, sy, dx, dy)) {
			return true;
		}
	}
	return false;
}

Chess::Chess(std::vector<std::string> names) {
	player_name = names;
	activate_players();
	populate_board();
}

void Chess::play_game() {
	// set initial turn
	int turn = 1;
	while (!check_win()) {
		std::cout << player_name.at(turn - 1) << "'s turn... " << std::endl;
		print_board();
		if (turn == 1) {
			player_turn(turn);
			turn = 2;
		}
		else {
			player_turn(turn);
			turn = 1;
		}

	}
	std::cout << "Game over... " << std::endl;
}

void Chess::get_input(int& sx, int& sy, int& dx, int& dy) {
	std::cout << "Enter row of piece to move" << std::endl;
	std::cin >> sx;
	std::cout << "Enter col of piece to move" << std::endl;
	std::cin >> sy;
	std::cout << "Enter row of destination" << std::endl;
	std::cin >> dx;
	std::cout << "Enter col of destination" << std::endl;
	std::cin >> dy;
}

void Chess::fill_empty_space() {
	std::pair<int, int> tmp_pair = { 0,0 };
	std::vector<std::pair<int, int>> tmp_vect;

	/* fill tmp vector with empty spaces */
	for (int i = 0; i < 8; i++) {
		tmp_vect.push_back(tmp_pair);
	}
	for (int i = 0; i < 8; i++) {
		if (i > 1 && i < 6) {
			/* set the space to empty */
			board.push_back(tmp_vect);
		}
	}
}

void Chess::create_player1_pieces() {
	/* creating special pieces */
	Piece* piece = nullptr;
	std::vector<std::pair<int, int>> tmp;
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 7) {
			piece = new Rook("R");
		}
		else if (i == 1 || i == 6) {
			piece = new Knight("N");
		}
		else if (i == 2 || i == 5) {
			piece = new Bishop("B");
		}
		else if (i == 3) {
			piece = new King("K");
		}
		else {
			piece = new Queen("Q");
		}
		pieces.push_back(piece);
	}

	/* create pairs and add to board */
	for (unsigned int i = 0; i < pieces.size(); i++) {
		std::pair<int, int> new_pair = { 1, i };
		tmp.push_back(new_pair);
	}

	board.push_back(tmp);
	tmp.clear();

	/* create pawns */
	for (int i = 0; i < 8; i++) {
		piece = new Pawn("P");
		pieces.push_back(piece);
	}

	/* create pairs and add to board */
	for (unsigned int i = 8; i < pieces.size(); i++) {
		std::pair<int, int> new_pair = { 1, i };
		tmp.push_back(new_pair);
	}

	board.push_back(tmp);

}

void Chess::create_player2_pieces() {
        Piece* piece = nullptr;
        std::vector<std::pair<int, int>> tmp;

	/* create pawns */
        for (int i = 0; i < 8; i++) {
                piece = new Pawn("p");
                pieces.push_back(piece);
        }

	for (unsigned int i = 16; i < pieces.size(); i++) {
		std::pair<int, int> new_pair = { 2, i };
                tmp.push_back(new_pair);
	}

	board.push_back(tmp);
	tmp.clear();	
	
	/* creating special pieces */
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 7) {
			piece = new Rook("r");
		}
		else if (i == 1 || i == 6) {
			piece = new Knight("n");
		}
		else if (i == 2 || i == 5) {
			piece = new Bishop("b");
		}
		else if (i == 3) {
			piece = new Queen("q");
		}
		else {
			piece = new King("k");
		}
		pieces.push_back(piece);
	}

	/* create pairs and add to board */
	for (unsigned int i = 24; i < pieces.size(); i++) {
		std::pair<int, int> new_pair = { 2, i };
		tmp.push_back(new_pair);
	}

	board.push_back(tmp);
}

void Chess::populate_board() {
	create_player1_pieces();
	fill_empty_space();
	create_player2_pieces();
}

void Chess::activate_players() {
	for (unsigned int i = 0; i < player_name.size(); i++) {
		player_status.push_back(true);
	}
}


















