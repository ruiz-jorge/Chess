#include "gtest/gtest.h"
#include "Game.hpp"
#include "Chess.hpp"


TEST(ChessTest, CheckStatus) {
	Piece* rook = new Rook("R");
	EXPECT_EQ(rook->returnStatus(), true);
}

/*TEST(ChessTest, ValidMove) {
	Piece* rook = new Rook("R");
        MoveInterface* mv = new StraightMove();
        std::vector<std::vector<std::pair<int,int>>> board;
        std::vector<Piece*> pieces;
        ASSERT_EQ(true, rook->setBehavior(mv, "Straight"));
        ASSERT_EQ(true, rook->move(board,pieces,0,1,4,1));
	EXPECT_EQ(1,rook->getmovesMade());
}*/

TEST(ChessTest, CheckWinPlayerTwo) {
	std::vector<std::string> names = {"player1","player2"};
	Game* test = new Chess(names);
	bool stat_test = test->check_win();
	EXPECT_EQ(stat_test, false);
	test->set_piece_status_false(0,3);
	stat_test = test->check_win();
	EXPECT_EQ(stat_test, true);
}

TEST(ChessTest, CheckWinPlayerOne) {
        std::vector<std::string> names = {"player1","player2"};
        Game* test = new Chess(names);
	bool stat_test = test->check_win();
	EXPECT_EQ(stat_test, false);
        test->set_piece_status_false(7,4);
        stat_test = test->check_win();
        EXPECT_EQ(stat_test, true);
}

TEST(ChessTest, CorrectPiecePlacement) {
        std::vector<std::string> names = {"player1","player2"};
        Game* test = new Chess(names);
        EXPECT_EQ(test->check_board_contents(0,0), "R");
	EXPECT_EQ(test->check_board_contents(7,3), "q");
	EXPECT_EQ(test->check_board_contents(1,7), "P");
	EXPECT_EQ(test->check_board_contents(6,4), "p");
}

TEST(ChessTest, ValidMoveGameBoard) {
        std::vector<std::string> names = {"player1","player2"};
        Game* test = new Chess(names);
        EXPECT_EQ(test->move_piece(1,0,3,0), true);
	EXPECT_EQ(test->move_piece(7,1,5,0), true);
}

TEST(ChessTest, InvalidMoveGameBoard) {
        std::vector<std::string> names = {"player1","player2"};
        Game* test = new Chess(names);
        EXPECT_EQ(test->move_piece(7,1,5,0), true);
        EXPECT_EQ(test->move_piece(7,1,0,0), false);
}
