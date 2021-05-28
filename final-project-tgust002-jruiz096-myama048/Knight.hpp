#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__
#include <vector>
#include <utility>
#include <cmath>
#include "MoveInterface.hpp"
#include "knightMove.hpp"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "Piece.hpp"


class Knight:public Piece{
        public:
          Knight(std::string name):Piece(name){move_limit=3;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
};



#endif	
