#include "gtest/gtest.h"
#include "Gameplay.hpp"


TEST (GameplayTest, PlayerNum){
	Gameplay* session= new Gameplay();
	session->setPlayerNum(2);
	EXPECT_EQ(2,session->getPlayerNum());
}

TEST (GameplayTest, PlayerNumZero){
        Gameplay* session= new Gameplay();
        session->setPlayerNum(0);
        EXPECT_EQ(0,session->getPlayerNum());
}

TEST (GameplayTest, addName){
	Gameplay* session= new Gameplay();
        session->setPlayerNum(2);
	session->addName("Jorge");
	session->addName("Masashi");
	EXPECT_EQ(session->getName(0),"Jorge");
}

TEST (GameplayTest, getNameEmpty){
	Gameplay* session= new Gameplay();
	EXPECT_EQ(session->getName(0),"No names entered");
}

