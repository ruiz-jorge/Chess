#include "Knight.hpp"          




//Knight::Knight(std::string name){move_limit=3;}
          
bool Knight::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Knight")return false;
          behavior=mv;
          return true;
          }
          
bool Knight::move (std::vector<std::vector<std::pair<int,int>>>& board,
          std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
          if(abs(startrow-endrow)+abs(startcol-endcol)>move_limit)return false;
          if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
          movesMade++;
          return true;
               
          } 
