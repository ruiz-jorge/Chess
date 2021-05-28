#include "Piece.hpp"
#include <vector>
#include <string>
#include <utility>
#include "MoveInterface.hpp"

Piece::Piece(std::string name){
	this->name=name;
	movesMade=0;
	behavior=nullptr;
	setStatus(true);
}

bool Piece::returnStatus(){return is_active;}

void Piece::setStatus(bool stat){is_active=stat;}

std::string Piece::getName(){return name;}

int Piece::getmovesMade(){return movesMade;}
