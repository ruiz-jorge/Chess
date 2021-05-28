#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Knight.hpp"
#include "MoveInterface.hpp"
#include "knightMove.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include <vector>
#include <utility>

TEST (KnightTest,CheckStatus){
	Piece* knight=new Knight("Knight");
	EXPECT_EQ(true, knight->returnStatus());
}

TEST (KnightTest, SetStatus){
        Piece* knight=new Knight("Knight");
	knight->setStatus(false);
        EXPECT_EQ(false, knight->returnStatus());

}

TEST (KnightTest, Check0Moves){
        Piece* knight=new Knight("Knight");
        EXPECT_EQ(0, knight->getmovesMade());

}

TEST (KnightTest, SetBehavior){
	Piece* knight= new Knight("Knight");
	MoveInterface* mv = new KnightMove();
	EXPECT_EQ(true, knight->setBehavior(mv, "Knight"));
}

TEST (KnightTest, SetBehaviorWrong){
        Piece* knight= new Knight("Knight");
        MoveInterface* mv = new KnightMove();
        EXPECT_EQ(false, knight->setBehavior(mv, "Straight"));
}

TEST (KnightTest, move){
	Piece* knight= new Knight("Knight");
        MoveInterface* mv = new KnightMove();
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
        pieces.push_back(knight);
	board[0][0].first=1;
	ASSERT_EQ(true, knight->setBehavior(mv, "Knight"));
	EXPECT_EQ(true, knight->move(board,pieces,0,0,1,2));
}

TEST (KnightTest, Checkmoves){
        Piece* knight= new Knight("Knight");
        MoveInterface* mv = new KnightMove();
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
        pieces.push_back(knight);
	board[0][0].first=1;
        ASSERT_EQ(true, knight->setBehavior(mv, "Knight"));
        ASSERT_EQ(true, knight->move(board,pieces,0,0,1,2));
	EXPECT_EQ(1,knight->getmovesMade());
}

