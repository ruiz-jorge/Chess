#ifndef  __PIECE_HPP__
#define  __PIECE_HPP__

#include <vector>
#include <utility>
#include <string>
//#include "MoveInterface.hpp"

class MoveInterface;
//class DiagonalMove;
//class StraightMove;
//class SideMove;
//class KnightMove;

class Piece{
    protected:
        std::string name;
        MoveInterface* behavior;
        bool is_active;
        int move_limit;
        int movesMade;
    public:
        Piece(std::string name);
        bool returnStatus();
        void setStatus(bool stat);
        virtual bool move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>,int startrow,int startcol,int endrow,int endcol)=0;
        std::string getName();
        virtual bool setBehavior(MoveInterface* mv,std::string)=0;
        int getmovesMade();
        


};



#endif	
