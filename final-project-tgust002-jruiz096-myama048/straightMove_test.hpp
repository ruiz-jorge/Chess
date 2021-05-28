#ifndef __STRAIGHTMOVE_TEST_HPP__
#define __STRAIGHTMOVE_TEST_HPP__

#include "MoveInterface.hpp"
#include "gtest/gtest.h"
#include "straightMove.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include <vector>
#include <utility>
//using namespace std;
//std::vector<std::vector<std::pair<int posiStatus, int idxPieceVector>>> board;
//std::vector<Pieces*> v_p;

TEST(straightMove, StraightByOne){ //passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int, int>>> board;
	std::vector<std::pair<int, int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0, 0, 1, 0));//moves made
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[1][0].first);
}

TEST(straightMove, BackByOne){ //passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{1,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 1,0,0,0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
}


TEST(straightMove, StraightByMultipleOpen){//passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{2,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,2}};
	board.push_back(v3);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0, 0, 2, 0));
	//mv->move(board, v_p, 0,0,2,0);
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
	EXPECT_EQ(2, board[2][0].first);
}


TEST(straightMove, BackByMultipleOpen){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{2,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{0,1}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,2}};
	board.push_back(v3);
	//std::vector<std::pair<int,int>> v4{{0,3}};
	//board.push_back(v4);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,2,0));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(2, board[2][0].first);
}


TEST(straightMove, SideMove){//passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(false, mv->move(board, v_p, 0, 0, 0, 3));
	EXPECT_EQ(1, board[0][0].first);
}

TEST(straightMove, PieceInBetween){//passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{2,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn); 
	EXPECT_EQ(false, mv->move(board, v_p, 0,0,3,0));
	EXPECT_EQ(1, board[0][0].first);
	EXPECT_EQ(2, board[1][0].first);
}

TEST(straightMove, PieceInBetween2){
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{0,0},{1,1}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{2,2},{0,3}};
	board.push_back(v2);
	std::vector<std::pair<int,int>> v3{{0,4},{2,5}};
	board.push_back(v3);
	std::vector<std::pair<int,int>> v4{{1,6},{0,7}};
	board.push_back(v4);
	std::vector<std::pair<int,int>> v5{{0,8},{0,9}};
	board.push_back(v5);
	Piece* pawn = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	EXPECT_EQ(false, mv->move(board, v_p, 1,0,1,4));
	EXPECT_EQ(1, board[0][1].first);
	EXPECT_EQ(0, board[1][1].first);
	EXPECT_EQ(2, board[2][1].first);
	EXPECT_EQ(0, board[3][1].first);
	EXPECT_EQ(0, board[4][1].first);
}


TEST(straightMove, TakePieceRightInFront){//passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{2,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	Piece* p2 = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	v_p.push_back(p2);
	EXPECT_EQ(true, mv->move(board, v_p, 0,0,1,0));
	EXPECT_EQ(0, board[0][0].first);
	EXPECT_EQ(1, board[1][0].first);
	EXPECT_EQ(false, v_p[1]->returnStatus());
	EXPECT_EQ(true, v_p[0]->returnStatus());
}


TEST(straightMove, TakePieceRightBack){ // passed
	std::vector<Piece*> v_p;
	std::vector<std::vector<std::pair<int,int>>> board;
	std::vector<std::pair<int,int>> v1{{1,0}};
	board.push_back(v1);
	std::vector<std::pair<int,int>> v2{{2,1}};
	board.push_back(v2);
	Piece* pawn = new Pawn("Pawn");
	Piece* a = new Pawn("Pawn");
	MoveInterface* mv = new StraightMove();
	pawn->setBehavior(mv, "Straight");
	v_p.push_back(pawn);
	v_p.push_back(a);
	EXPECT_EQ(true, mv->move(board, v_p, 1,0,0,0));
	EXPECT_EQ(2, board[0][0].first);
	EXPECT_EQ(0, board[1][0].first);
	EXPECT_EQ(false, v_p[0]->returnStatus());
}

#endif
