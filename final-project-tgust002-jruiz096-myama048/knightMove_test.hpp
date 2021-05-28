#ifndef __STRAIGHTMOVE_TEST_HPP__
#define __STRAIGHTMOVE_TEST_HPP__

#include "MoveInterface.hpp"
#include "gtest/gtest.h"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include <vector>
#include <utility>
#include "Rook.hpp"
#include "Bishop.hpp"


//using namespace std;
//std::vector<std::vector<std::pair<int posiStatus, int idxPieceVector>>> board;
//std::vector<Pieces*> v_p;

TEST(knightMove, Empty_x2y1){ //
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int, int>>> board;
	std::vector<std::pair<int, int>> v1{{1,0},{0,1},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int, int>> v2{{0,2},{0,3},{0,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0, 0, 1, 2));//moves made
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[1][2].first);
}

TEST(knightMove, Empty_x1y2){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{2,0},{1,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,2},{0,3}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,2},{0,2}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,2,1));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(2, board[2][1].first);
	EXPECT_EQ(1, board[0][1].first);
}

TEST(knightMove, Empty_x2y_1){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{2,1},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{1,0},{0,1},{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,1},{0,1},{0,1}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 1,0,0,2));
	EXPECT_EQ(0, board[1][0].first);
	EXPECT_EQ(1, board[0][2].first);
	EXPECT_EQ(2, board[0][1].first);
}

TEST(knightMove, Empty_x1y_2){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{0,1},{0,2}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,4},{0,5},{0,6}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{1,0},{0,3},{0,3}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 2,0,0,1));
	EXPECT_EQ(1, board[0][1].first);
	EXPECT_EQ(0, board[2][0].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(0, board[1][0].first);
}

TEST(knightMove, Empty_x_1y_2){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{0,1},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1},{0,1},{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,1},{0,1},{3,0}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knigt");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board,v_p,2,2,0,1));
	EXPECT_EQ(3, board[0][1].first);
	EXPECT_EQ(0, board[2][2].first);
}

TEST(knightMove, Empty_x_2y_1){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{0,1},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1},{0,1},{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,1},{0,1},{1,0}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knigth");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board,v_p,2,2,1,0));
	EXPECT_EQ(1, board[1][0].first);
	EXPECT_EQ(0, board[2][2].first);
}

TEST(knightMove, Empty_x_2y1){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{0,1},{0,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1},{0,1},{1,0}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,1},{0,1},{0,1}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board,v_p,1,2,2,0));
	EXPECT_EQ(1, board[2][0].first);
	EXPECT_EQ(0, board[1][2].first);
}

TEST(knightMove, Empty_x_1y2){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,1},{0,1},{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1},{0,1},{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,1},{0,1},{0,1}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board,v_p,0,2,2,1));
	EXPECT_EQ(1, board[2][1].first);
	EXPECT_EQ(0, board[0][2].first);
}

TEST(knightMove, StraightMove){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn);
	EXPECT_EQ(false, mv->move(board, v_p, 0, 0, 1, 0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
}

TEST(knightMove, TakePiece_x2y1){//
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0},{0,2},{2,2},{0,3}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,4},{0,5},{2,1},{0,7}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,8},{0,9},{2,10},{0,11}};
	board.push_back(v3);
	std::vector<std::pair<int,int>> v4{{0,12},{0,13},{0,14},{0,15}};
	board.push_back(v4);
	Piece* pawn = new Pawn("Pawn");
	Piece* p = new Pawn("Pawn");
	MoveInterface* mv = new KnightMove();
	pawn->setBehavior(mv, "Knight");
	v_p.push_back(pawn); 
	v_p.push_back(p);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,1,2));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[1][2].first);
	//EXPECT_EQ(false, v_p[board[2][2].second]->returnStatus());
}


#endif
