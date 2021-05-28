#ifndef __GAMEPLAY_HPP__
#define __GAMEPLAY_HPP__
#include <vector>
#include <string>
#include "Game.hpp"
//#include "Chess.hpp"
#include "Checkers.hpp"
//#include "MakeyourOwn.hpp"
class Gameplay{
    private:
        int gamechoice;
        int playernum;
        Game* game;
        std::vector<std::string>names;
    public:
	Gameplay(){
		game=nullptr;
		gamechoice=0;
		playernum=0;}
        void SetNames();
	void inputPlayernum();
	void setPlayerNum(int);
	int getPlayerNum();
	void addName(std::string);
	std::string getName(int);
        void ChooseGame();
        void PrintNames();
        void Menu();
        void PrintBoard();
        void Startover();
        void Play();
        void MakeGame();
        void PlayAgain();
};


#endif	
