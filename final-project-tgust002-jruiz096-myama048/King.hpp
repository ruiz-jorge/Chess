#ifndef __KING_HPP__
#define __KING_HPP__
#include <vector>
#include <utility>
#include <cmath>
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include "Piece.hpp"


class King:public Piece{
        public:
          King(std::string name):Piece(name){move_limit=1;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
};



#endif	
