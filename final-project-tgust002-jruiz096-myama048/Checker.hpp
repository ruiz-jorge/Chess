#ifndef __CHECKER_HPP__
#define __CHECKER_HPP__
#include <vector>
#include <utility>
#include <cmath>
#include "MoveInterface.hpp"
#include "checkerMove.hpp"
#include "Piece.hpp"



class Checker:public Piece{
        public:
          Checker(std::string name):Piece(name){move_limit=2;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
};



#endif	
