#include "Pawn.hpp"

          
//Pawn::Pawn(std::string name){move_limit=2;}
          
bool Pawn::setBehavior(MoveInterface* mv,std::string mvtype){
          if (behavior!=nullptr)delete[]behavior;
          if (mvtype!="Straight"&&mvtype!="Diagonal")return false;
          behavior=mv;
          return true;
          }
          
bool Pawn::move (std::vector<std::vector<std::pair<int,int>>>& board,
          std::vector<Piece*>pieces,int startrow,int startcol,int endrow,int endcol){
          if(abs(startrow-endrow)>move_limit||abs(startcol-endcol)>move_limit)return false;
          if(startcol!=endcol&&(board[endrow][endcol].first==board[startrow][startcol].first||board[endrow][endcol].first==0))return false;
          if (behavior->move(board,pieces,startrow,startcol,endrow,endcol)==false)return false;
          move_limit=1;
          movesMade++;
          return true;
               
          } 
