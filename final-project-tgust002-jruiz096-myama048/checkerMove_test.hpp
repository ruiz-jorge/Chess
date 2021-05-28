#ifndef __STRAIGHTMOVE_TEST_HPP__
#define __STRAIGHTMOVE_TEST_HPP__

#include "MoveInterface.hpp"
#include "gtest/gtest.h"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "checkerMove.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include <vector>
#include <utility>
#include "Rook.hpp"
#include "Bishop.hpp"


//using namespace std;
//std::vector<std::vector<std::pair<int posiStatus, int idxPieceVector>>> board;
//std::vector<Pieces*> v_p;

TEST(checkerMove, UpperRightByOne){ //
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int, int>>> board;
	std::vector<std::pair<int, int>> v1{{1,0},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int, int>> v2{{0,2},{0,3}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new CheckerMove();
	pawn->setBehavior(mv, "Checker");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0, 0, 1, 1));//moves made
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[1][1].first);
}

TEST(checkerMove, UpperLeftByOne){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{1,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,2},{0,3}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new CheckerMove();
	pawn->setBehavior(mv, "Checker");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,1,1,0));
	EXPECT_EQ(0, board[0][1].first);
	EXPECT_EQ(1, board[1][0].first);
}
/*
TEST(diagonalMove, LowerRightByMultipleOpen){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{2,1},{0,2},{0,3},{0,4}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,5},{0,6},{0,7},{0,8},{0,9}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,10},{0,11},{0,12},{0,13},{0,14}};
	board.push_back(v3);
	std::vector<std::pair<int,int>> v4{{0,15},{1,16},{0,17},{0,18},{0,19}};
	board.push_back(v4);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new DiagonalMove();
	pawn->setBehavior(mv, "Diagonal");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 3,1,0,4));
	//mv->move(board, v_p, 0,0,2,0);
	EXPECT_EQ(0, board[3][1].first);
	EXPECT_EQ(0, board[2][2].first);
	EXPECT_EQ(0, board[1][3].first);
	EXPECT_EQ(1, board[0][4].first);
	EXPECT_EQ(2, board[0][1].first);
}

TEST(diagonalMove, LowerLeftByMultipleOpen){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{0,1},{0,2},{0,3}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,4},{0,5},{0,6},{0,7}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,8},{0,9},{0,10},{0,11}};
	board.push_back(v3);
	std::vector<std::pair<int,int>> v4{{0,12},{0,13},{0,14},{1,0}};
	board.push_back(v4);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new DiagonalMove();
	pawn->setBehavior(mv, "Diagonal");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 3,3,0,0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(0, board[2][2].first);
	EXPECT_EQ(0, board[3][3].first);
}
*/
TEST(checkerMove, StraightMove){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new CheckerMove();
	pawn->setBehavior(mv, "Checker");
	v_p.push_back(pawn);
	EXPECT_EQ(false, mv->move(board, v_p, 0, 0, 1, 0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
}

TEST(checkerMove, JumpingPieceUpperRight){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{0,1},{2,2},{0,3}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,4},{2,1},{0,6},{0,7}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,8},{0,9},{0,10},{0,11}};
	board.push_back(v3);
	std::vector<std::pair<int,int>> v4{{0,12},{0,13},{0,14},{0,15}};
	board.push_back(v4);
	Piece* pawn = new Pawn("Pawn");
	Piece* p = new Pawn("Pawn");
	MoveInterface* mv = new CheckerMove();
	pawn->setBehavior(mv, "Checker");
	v_p.push_back(pawn); 
	v_p.push_back(p);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,2,2));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(1, board[2][2].first);
	EXPECT_EQ(0, board[3][3].first);
}

TEST(checkerMove, JumpingPieceUpperLeft){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{0,1},{2,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{2,2},{3,1},{0,3}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,3},{0,3},{0,3}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	Piece* p = new Pawn("Pawn");
	MoveInterface* mv = new CheckerMove();
	pawn->setBehavior(mv, "Checker");
	v_p.push_back(pawn);
	v_p.push_back(p);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,2,2));
	EXPECT_EQ(1, board[2][2].first);
	EXPECT_EQ(0, board[1][1].first); //<----
	EXPECT_EQ(0, board[0][0].first);
}

TEST(checkerMove, JumpOverEmpty){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{2,0},{0,3}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{1,1},{0,3},{0,3}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,3},{0,3},{0,3}};
	board.push_back(v3);
	Piece* rook = new Rook("Rook");
	Piece* r = new Rook("Rook");
	MoveInterface* mv = new CheckerMove();
	rook->setBehavior(mv, "Checker");
	v_p.push_back(rook);
	v_p.push_back(r);
	EXPECT_EQ(false, mv->move(board, v_p, 0,0,2,2));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(0, board[2][2].first);
}

TEST(checkerMove, BigJump){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{0,2},{0,2},{0,2}};
	std::vector<std::pair<int,int>> v2{{0,2},{0,2},{0,2},{0,2}};
	std::vector<std::pair<int,int>> v3{{0,2},{0,2},{0,2},{0,2}};
	std::vector<std::pair<int,int>> v4{{0,2},{0,2},{0,2},{0,2}};
	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	Piece* r = new Rook("Rook");
	MoveInterface* mv = new CheckerMove();
	r->setBehavior(mv, "Checker");
	v_p.push_back(r);
	EXPECT_EQ(false, mv->move(board,v_p,0,0,3,3));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(0, board[2][2].first);
	EXPECT_EQ(0, board[3][3].first);
}

#endif
