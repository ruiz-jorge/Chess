#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__
#include <vector>
#include <utility>
#include "Piece.hpp"
#include "MoveInterface.hpp"
#include "diagonalMove.hpp"
#include "straightMove.hpp"
#include "sideMove.hpp"
#include "knightMove.hpp"


class Bishop : public Piece{
        public:
          Bishop(std::string name):Piece(name){move_limit=0;}
          bool setBehavior(MoveInterface* mv,std::string mvtype);
          bool move (std::vector<std::vector<std::pair<int,int>>>& board,
              std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol);
};



#endif	
