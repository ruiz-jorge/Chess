#include "Checker.hpp"

//Checker::Checker(std::string name){move_limit=2;}
          
bool Checker::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Checker")return false;
          behavior=mv;
          return true;
          }
          

bool Checker::move (std::vector<std::vector<std::pair<int,int>>>& board,
               std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
               if (abs(startrow-endrow)>move_limit||abs(startcol-endcol)>move_limit)return false;
               if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
               movesMade++;
               return true;
               
          } 
