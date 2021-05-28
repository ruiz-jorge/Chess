#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Checker.hpp"
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "checkerMove.hpp"
#include "diagonalMove.hpp"
#include <vector>
#include <utility>

TEST (CheckerTest,CheckStatus){
	Piece* check=new Checker("Checker");
	EXPECT_EQ(true, check->returnStatus());
}

TEST (CheckerTest, SetStatus){
        Piece* check=new Checker("Checker");
	check->setStatus(false);
        EXPECT_EQ(false, check->returnStatus());

}

TEST (CheckerTest, Check0Moves){
        Piece* check=new Bishop("Checker");
        EXPECT_EQ(0, check->getmovesMade());

}

TEST (CheckerTest, SetBehavior){
	Piece* check= new Checker("Check");
	MoveInterface* mv = new CheckerMove();
	EXPECT_EQ(true, check->setBehavior(mv, "Checker"));
}

TEST (CheckerTest, SetBehaviorWrong){
        Piece* check= new Checker("Checker");
        MoveInterface* mv = new StraightMove();
        EXPECT_EQ(false, check->setBehavior(mv, "Straight"));
}

TEST (CheckerTest, move){
	Piece* check= new Checker("Checker");
        MoveInterface* mv = new CheckerMove();
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
        pieces.push_back(check);
	board[0][2].first=1;
	ASSERT_EQ(true, check->setBehavior(mv, "Checker"));
	EXPECT_EQ(false, check->move(board,pieces,0,2,3,5));
}

TEST (CheckerTest, Checkmoves){
        Piece* check= new Checker("check");
        MoveInterface* mv = new CheckerMove();
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
        pieces.push_back(check);
	board[0][1].first=1;
        ASSERT_EQ(true, check->setBehavior(mv, "Checker"));
        ASSERT_EQ(true, check->move(board,pieces,0,1,1,2));
	EXPECT_EQ(1,check->getmovesMade());
}

