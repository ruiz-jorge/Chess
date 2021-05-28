#ifndef __CHECKERS_HPP__
#define __CHECKERS_HPP__

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "Game.hpp"
#include "Piece.hpp"
#include "Checker.hpp"
#include "MoveInterface.hpp"
#include "checkerMove.hpp"
#include <cmath>



class Checkers: public Game{
 
    public:
        Checkers(std::vector<std::string>names){
            for (auto i: names){
                player_name.push_back(i);
            }
            for (int i=0; i<names.size();i++){
                player_status.push_back(true);
            }
            fillBoard();
            makePieces();
            
        }
        bool check_win(){
                int i=0;
                for (auto j: player_status)if (j==true)i++;
                if (i>1) return false;
                else return true;
            }
            void play_game();
            bool move_piece(int,int,int,int);
            void player_turn(int);

	//~Checkers(){};
            void makePieces();
            void fillBoard();
            void checkPlayers();
            void nextMove(int, int);
            void getStartL(int&,int&);
            void getEndL(int&,int&);
            void elimPiece(int i){
                pieces[i]->setStatus(false);//for testing purposes only
            }
            void elimPlayer(int);

};

#endif
