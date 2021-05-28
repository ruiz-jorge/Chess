#ifndef __DIAGONALMOVE_HPP__
#define __DIAGONALMOVE_HPP__
//Mock class for testing puposes
#include <vector>
#include <utility>
//#include "Piece.hpp"
#include "MoveInterface.hpp"

//class Piece;

class DiagonalMove : public MoveInterface{
	public:
		bool move(std::vector<std::vector<std::pair<int,int>>>board, 
				std::vector<Piece*>pieces,int sx,int sy,int dx,int dy);
};


#endif
