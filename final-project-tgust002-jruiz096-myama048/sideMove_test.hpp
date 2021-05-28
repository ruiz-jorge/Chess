#ifndef __STRAIGHTMOVE_TEST_HPP__
#define __STRAIGHTMOVE_TEST_HPP__

#include "MoveInterface.hpp"
#include "gtest/gtest.h"
#include "sideMove.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include <vector>
#include <utility>
#include "Rook.hpp"

//using namespace std;
//std::vector<std::vector<std::pair<int posiStatus, int idxPieceVector>>> board;
//std::vector<Pieces*> v_p;

TEST(sideMove, RightByOne){ //
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int, int>>> board;
	std::vector<std::pair<int, int>> v1{{1,0},{0,1}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0, 0, 0, 1));//moves made
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[0][1].first);
}

TEST(sideMove, LeftByOne){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{1,0}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,1,0,0));
	EXPECT_EQ(0, board[0][1].first);
	EXPECT_EQ(1, board[0][0].first);
}

TEST(sideMove, RightByMultipleOpen){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{2,0},{0,2},{0,3},{0,4}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,1,0,4));
	//mv->move(board, v_p, 0,0,2,0);
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(0, board[0][1].first);
	EXPECT_EQ(0, board[0][2].first);
	EXPECT_EQ(0, board[0][3].first);
	EXPECT_EQ(2, board[0][4].first);
}

TEST(sideMove, LeftByMultipleOpen){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{0,1},{0,2},{0,3},{0,4},{3,0}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,5,0,0));
	EXPECT_EQ(3, board[0][0].first);
	EXPECT_EQ(0, board[0][1].first);
	EXPECT_EQ(0, board[0][2].first);
	EXPECT_EQ(0, board[0][3].first);
	EXPECT_EQ(0, board[0][4].first);
	EXPECT_EQ(0, board[0][5].first);
}

TEST(sideMove, StraightMove){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	EXPECT_EQ(false, mv->move(board, v_p, 0, 0, 1, 0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
}

TEST(sideMove, PieceInBetween){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{0,1},{2,2},{0,3}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn); 
	EXPECT_EQ(false, mv->move(board, v_p, 0,0,0,3));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[0][1].first);
	EXPECT_EQ(2, board[0][2].first);
	EXPECT_EQ(0, board[0][3].first);
}

TEST(sideMove, TakePieceRight){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{2,1}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	Piece* p = new Pawn("Pawn");
	MoveInterface* mv = new SideMove();
	pawn->setBehavior(mv, "Side");
	v_p.push_back(pawn);
	v_p.push_back(p);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,0,1));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[0][1].first);
}

TEST(sideMove, TakePieceLeft){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}, {2,1}};
	board.push_back(v1);
	Piece* rook = new Rook("Rook");
	Piece* r = new Rook("Rook");
	MoveInterface* mv = new SideMove();
	rook->setBehavior(mv, "Side");
	v_p.push_back(rook);
	v_p.push_back(r);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,0,1));
}

#endif
