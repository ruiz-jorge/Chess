#include "Bishop.hpp"

//Bishop::Bishop(std::string name){move_limit=0;}
bool Bishop::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Diagonal")return false;
          behavior=mv;
          return true;
          }
bool Bishop::move (std::vector<std::vector<std::pair<int,int>>>& board,
          std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
          if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
          movesMade++;
          return true;}
               



