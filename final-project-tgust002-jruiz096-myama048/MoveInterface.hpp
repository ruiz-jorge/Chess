#ifndef __MOVE_INTERFACE_HPP__
#define __MOVE_INTERFACE_HPP__

#include<vector>
//#include<iostream>
#include<utility>
//#include "Piece.hpp"

class Piece;

class MoveInterface {
	public:
		virtual bool move(std::vector<std::vector<std::pair<int, int>>> &Board, std::vector<Piece*> v_p, int sy, int sx, int dy, int dx) = 0;
};

#endif
