#ifndef __CHECKERS_TEST_HPP__
#define __CHECKERS_TEST_HPP__

#include "Game.hpp"
#include "Checkers.hpp"
#include <vector>
#include "gtest/gtest.h"

TEST(Checkers, Check_winF){
	std::vector<std::string>names;
	names.push_back("Thomas");
	names.push_back("Jorge");
	Checkers* g=new Checkers(names);
	EXPECT_EQ(false, g->check_win());
}

TEST(Checkers, Check_winT){
	std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
	g->elimPlayer(0);
	EXPECT_EQ(true, g->check_win());

}


TEST(Checkers, elimPlayerInvld){
	std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
	g->elimPlayer(4);
	EXPECT_EQ(false, g->check_win());
}

TEST(Checkers, movePiece){
	std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
	EXPECT_EQ(true,g->move_piece(2,1,3,0));
}

TEST(Checkers, movePieceWrong){
        std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
        EXPECT_EQ(false,g->move_piece(2,1,3,5));
}


TEST(Checkers, CheckPlayersT){
	std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
	g->checkPlayers();
	g->elimPiece(0);
	EXPECT_EQ(false,g->check_win());	
}

TEST(Checkers, CheckPlayersF){
	std::vector<std::string>names;
        names.push_back("Thomas");
        names.push_back("Jorge");
        Checkers* g=new Checkers(names);
	g->elimPiece(0);
	g->elimPiece(1);
	g->elimPiece(2);
	g->elimPiece(3);
	g->elimPiece(4);
	g->elimPiece(5);
	g->elimPiece(6);
	g->elimPiece(7);
	g->elimPiece(8);
	g->elimPiece(9);
	g->elimPiece(10);
	g->elimPiece(11);
	g->checkPlayers();
        EXPECT_EQ(true,g->check_win());
	
}


#endif
