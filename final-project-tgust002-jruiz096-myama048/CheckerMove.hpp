#ifndef __CHECKERMOVE_HPP__
#define __CHECKERMOVE_HPP__
//Mock class for testing puposes
#include <vector>
#include <utility>
#include "MoveInterface.hpp"

class CheckerMove:public MoveInterface{
	public:
		bool move(std::vector<std::vector<std::pair<int,int>>>board, 
				std::vector<Piece*>pieces,int sx,int sy,int dx,int dy);
};


#endif
