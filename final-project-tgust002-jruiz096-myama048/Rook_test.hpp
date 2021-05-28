#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Rook.hpp"
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include <vector>
#include <utility>

TEST (RookTest,CheckStatus){
	Piece* rook=new Rook("Black Rook");
	EXPECT_EQ(true, rook->returnStatus());
}

TEST (RookTest, SetStatus){
        Piece* rook=new Rook("Black Rook");
	rook->setStatus(false);
        EXPECT_EQ(false, rook->returnStatus());

}

TEST (RookTest, Check0Moves){
        Piece* rook=new Rook("Black Rook");
        EXPECT_EQ(0, rook->getmovesMade());

}

TEST (RookTest, SetBehaviorWrong){
	Piece* rook= new Rook("Black Rook");
	MoveInterface* mv = new DiagonalMove();
	EXPECT_EQ(false, rook->setBehavior(mv, "Diagonal"));
}

TEST (RookTest, SetBehavior){
        Piece* rook= new Rook("Black Rook");
        MoveInterface* mv = new StraightMove();
        EXPECT_EQ(true, rook->setBehavior(mv, "Straight"));
}

TEST (RookTest, move){
	Piece* rook= new Rook("Black Rook");
        MoveInterface* mv = new StraightMove();
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<Piece*> pieces;
        std::vector<std::pair<int,int>> v;
        for (int i=0; i<8; i++){
        std::pair<int,int>space(0,0);
        v.push_back(space);
        }
        for (int i=0; i<8; i++){
        board.push_back(v);
        }
        pieces.push_back(rook);
	board[0][2].first=1;
	ASSERT_EQ(true, rook->setBehavior(mv, "Straight"));
	EXPECT_EQ(true, rook->move(board,pieces,0,2,7,2));
}

TEST (RookTest, Checkmoves){
        Piece* rook= new Rook("Black Rook");
        MoveInterface* mv = new StraightMove();
        std::vector<std::vector<std::pair<int,int>>> board;
        std::vector<Piece*> pieces;
        std::vector<std::pair<int,int>> v;
        for (int i=0; i<8; i++){
        std::pair<int,int>space(0,0);
        v.push_back(space);
        }
        for (int i=0; i<8; i++){
        board.push_back(v);
        }
        pieces.push_back(rook);
	board[0][2].first=1;
        ASSERT_EQ(true, rook->setBehavior(mv, "Straight"));
        ASSERT_EQ(true, rook->move(board,pieces,0,2,7,2));
	EXPECT_EQ(1,rook->getmovesMade());
}

