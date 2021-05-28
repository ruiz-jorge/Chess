#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Queen.hpp"
#include "MoveInterface.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include <vector>
#include <utility>

TEST (QueenTest,CheckStatus){
	Piece* qn=new Queen("Queen");
	EXPECT_EQ(true, qn->returnStatus());
}

TEST (QueenTest, SetStatus){
        Piece* qn=new Queen("Queen");
	qn->setStatus(false);
        EXPECT_EQ(false, qn->returnStatus());

}

TEST (QueenTest, Check0Moves){
        Piece* qn=new Queen("Queen");
        EXPECT_EQ(0, qn->getmovesMade());

}

TEST (QueenTest, SetBehavior){
	Piece* qn= new Queen("Queen");
	MoveInterface* mv = new DiagonalMove();
	EXPECT_EQ(true, qn->setBehavior(mv, "Diagonal"));
}

TEST (QueenTest, SetBehaviorWrong){
        Piece* qn= new Queen("Queen");
        MoveInterface* mv = new KnightMove();
        EXPECT_EQ(false, qn->setBehavior(mv, "Knight"));
}

TEST (QueenTest, move){
	Piece* qn= new Queen("Queen");
        MoveInterface* mv = new SideMove();
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
	ASSERT_EQ(true, qn->setBehavior(mv, "Side"));
	pieces.push_back(qn);
	board[0][2].first=1;
	board[0][2].second=0;
	EXPECT_EQ(true, qn->move(board,pieces,0,2,0,5));
}

TEST (QueenTest, Checkmoves){
        Piece* qn= new Queen("Queen");
        MoveInterface* mv = new DiagonalMove();
        std::vector<std::vector<std::pair<int,int>>> board;
        std::vector<Piece*> pieces;
        ASSERT_EQ(true, qn->setBehavior(mv, "Diagonal"));
        std::vector<std::pair<int,int>> v;
        for (int i=0; i<8; i++){
                std::pair<int,int>space(0,0);
                v.push_back(space);
        }
        for (int i=0; i<8; i++){
                board.push_back(v);
        }
	board[0][2].first=1;
        board[0][2].second=0;
	pieces.push_back(qn);
        ASSERT_EQ(true, qn->move(board,pieces,0,2,3,5));
	EXPECT_EQ(1,qn->getmovesMade());
}

