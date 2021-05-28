#ifndef __MAKEYOUROWN_HPP__
#define __MAKEYOUROWN_HPP__
//mock class for unit testing delete when Game branch is merged in
//
#include <vector>
#include <string>
#include "Game.hpp"

class MakeyourOwn: public Game{
public:
	MakeyourOwn(std::vector<std::string>):Game(){}

};

#endif
