#ifndef __PAWN_HPP__
#define __PAWN_HPP__
#include <vector>
#include <utility>
#include <cmath>
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "diagonalMove.hpp"
#include "sideMove.hpp"
#include "knightMove.hpp"
#include "Piece.hpp"

class Pawn:public Piece{
        public:
          Pawn(std::string name):Piece(name){move_limit=2;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
};



#endif	
