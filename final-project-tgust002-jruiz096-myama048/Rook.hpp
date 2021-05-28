#ifndef __ROOK_HPP__
#define __ROOK_HPP__
#include <vector>
#include <utility>
#include "MoveInterface.hpp"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "diagonalMove.hpp"
#include "knightMove.hpp"
#include "Piece.hpp"

class Rook:public Piece{
        public:
          Rook(std::string name):Piece(name){move_limit=3;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
               
};



#endif	
