#include "gtest/gtest.h"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "MoveInterface.hpp"
#include "sideMove.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include <vector>
#include <utility>

TEST (PawnTest,CheckStatus){
	Piece* pn=new Pawn("Pawn");
	EXPECT_EQ(true, pn->returnStatus());
}

TEST (PawnTest, SetStatus){
        Piece* pn=new Pawn("Pawn");
	pn->setStatus(false);
        EXPECT_EQ(false, pn->returnStatus());

}

TEST (PawnTest, Check0Moves){
        Piece* pn=new Pawn("Pawn");
        EXPECT_EQ(0, pn->getmovesMade());

}

TEST (PawnTest, SetBehavior){
	Piece* pn= new Pawn("Pawn");
	MoveInterface* mv = new DiagonalMove();
	EXPECT_EQ(true, pn->setBehavior(mv, "Diagonal"));
}

TEST (PawnTest, SetBehaviorWrong){
        Piece* pn= new Pawn("King");
        MoveInterface* mv = new KnightMove();
        EXPECT_EQ(false, pn->setBehavior(mv, "Knight"));
}

TEST (PawnTest, move){
	Piece* pn= new Pawn("Pawn");
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
	pieces.push_back(pn);
	board[0][2].first=1;
	ASSERT_EQ(true, pn->setBehavior(mv, "Straight"));
	EXPECT_EQ(true, pn->move(board,pieces,0,2,2,2));
	EXPECT_EQ(false, pn->move(board,pieces,2,2,4,2));

}

TEST (PawnTest, Checkmoves){
        Piece* pn= new Pawn("Pawn");
        MoveInterface* mv = new DiagonalMove();
        std::vector<std::vector<std::pair<int,int>>> board;
        std::vector<std::pair<int,int>> v;
        for (int i=0; i<8; i++){
        std::pair<int,int>space(0,0);
        v.push_back(space);
        }
        for (int i=0; i<8; i++){
        board.push_back(v);
        }
	board[0][0].first=1;
	board[0][0].second=0;
	board[1][1].first=2;
	board[1][1].second=1;
	Piece* pn1= new Pawn("Pawn");
	std::vector<Piece*> pieces;
	pieces.push_back(pn);
	pieces.push_back(pn1);
        ASSERT_EQ(true, pn->setBehavior(mv, "Diagonal"));
        EXPECT_EQ(true, pn->move(board,pieces,0,0,1,1));
	EXPECT_EQ(1,pn->getmovesMade());
}

TEST (PawnTest, Checkwrongmoves){
        Piece* pn= new Pawn("Pawn");
        MoveInterface* mv = new DiagonalMove();
        std::vector<std::vector<std::pair<int,int>>> board;
        std::vector<std::pair<int,int>>vec{{1,3}};
        board.push_back(vec);
        std::vector<std::pair<int,int>>vec1{{0,2},{1,2}};
        board.push_back(vec1);
        std::vector<Piece*> pieces;
        ASSERT_EQ(true, pn->setBehavior(mv, "Diagonal"));
        EXPECT_EQ(false, pn->move(board,pieces,0,0,1,1));
        EXPECT_EQ(0,pn->getmovesMade());
}


