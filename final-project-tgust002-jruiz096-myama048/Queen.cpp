#include "Queen.hpp"

          
//Queen::Queen(std::string name){move_limit=0;}
          
bool Queen::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Straight"&&mvtype!="Side"&&mvtype!="Diagonal")return false;
          behavior=mv;
          return true;
          }
          
bool Queen::move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
               if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
               movesMade++;
               return true;
               
          } 

