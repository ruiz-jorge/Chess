#include "King.hpp"
          
//King::King(std::string name){move_limit=1;}
          
bool King::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Straight"&&mvtype!="Side"&&mvtype!="Diagonal")return false;
          behavior=mv;
          return true;
          }
          
bool King::move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
               if(abs(startrow-endrow)>move_limit||abs(startcol-endcol)>move_limit)return false;
               if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
               movesMade++;
               return true;
               
          } 
