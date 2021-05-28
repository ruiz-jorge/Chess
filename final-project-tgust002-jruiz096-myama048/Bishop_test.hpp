#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include <vector>
#include <utility>

TEST (BishopTest,CheckStatus){
	Piece* bish=new Bishop("White Bishop");
	EXPECT_EQ(true, bish->returnStatus());
}

TEST (BishopTest, SetStatus){
        Piece* bish=new Bishop("White Bishop");
	bish->setStatus(false);
        EXPECT_EQ(false, bish->returnStatus());

}

TEST (BishopTest, Check0Moves){
        Piece* bish=new Bishop("White Bishop");
        EXPECT_EQ(0, bish->getmovesMade());

}

TEST (BishopTest, SetBehavior){
	Piece* bish= new Bishop("White Bishop");
	MoveInterface* mv = new DiagonalMove();
	EXPECT_EQ(true, bish->setBehavior(mv, "Diagonal"));
}

TEST (BishopTest, SetBehaviorWrong){
        Piece* bish= new Bishop("White Bishop");
        MoveInterface* mv = new StraightMove();
        EXPECT_EQ(false, bish->setBehavior(mv, "Straight"));
}

TEST (BishopTest, move){
	Piece* bish= new Bishop("White Bishop");
        MoveInterface* mv = new DiagonalMove();
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
        pieces.push_back(bish);
	board[0][2].first=1;
	ASSERT_EQ(true, bish->setBehavior(mv, "Diagonal"));
	EXPECT_EQ(true, bish->move(board,pieces,0,2,3,5));
}

TEST (BishopTest, Checkmoves){
        Piece* bish= new Bishop("White Bishop");
        MoveInterface* mv = new DiagonalMove();
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
        pieces.push_back(bish);
	board[0][2].first=1;
        ASSERT_EQ(true, bish->setBehavior(mv, "Diagonal"));
        ASSERT_EQ(true, bish->move(board,pieces,0,2,3,5));
	EXPECT_EQ(1,bish->getmovesMade());
}

