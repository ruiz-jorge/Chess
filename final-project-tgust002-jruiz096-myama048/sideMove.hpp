#ifndef __SIDE_MOVE_HPP__
#define __SIDE_MOVE_HPP__

#include "MoveInterface.hpp"
#include <utility>
#include <vector>
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Piece.hpp"

class SideMove : public MoveInterface {
	public:
		bool move(std::vector<std::vector<std::pair<int, int>>> &Board, std::vector<Piece*> v_p, int sy, int sx, int dy, int dx){
			
			if(sx == dx){ 
				//printf("can't go straight\n");
				return false;
			}
			if(sy != dy){
				//printf("need to move\n");
				return false;
			}
			if(!(sx >= 0 && sx <= 7 && sy >= 0 && sy <= 7 && dx >= 0 && dx <= 7 && dy >= 0 && dy <= 7)){
				//printf("not in range\n");
				return false;
			}
			if(sx < dx) { //moving to the right	
				for(int i = sx + 1; i < dx; i++){ // loop to check all spots in between sy & (dy - 1) are open
					if(Board[sy][i].first != 0){ // 0 means the board is empty
						//printf("there's oppenet's piece\n");
						return false;
					}
				}
			}
			else{ // moving to the left
				for(int i = sx - 1; i > dx; i--){
					if(Board[sy][i].first != 0){
						return false;
					}
				}
			}
	
			if(Board[sy][sx].first == Board[dy][dx].first){ // there's other piece on [dx][dy]
				//printf("there's your piece\n");
				return false;		// 1 means your piece
			}	
				
			else if(Board[dy][dx].first != 0){ // 2 means that there's enemy's piece
				//printf("take it\n");
				v_p[Board[dy][dx].second]->setStatus(false);// set status of enemy's piece to be taken
			}

			//printf("[dx][dy]: ");
			Board[dy][dx].first = Board[sy][sx].first;// new location to be occupied
			Board[dy][dx].second= Board[sy][sx].second;
			//printf("set dx,dy original\n");
			//printf("%d\n", Board[dx][dy].first);
			//printf("[sx][sy]: ");
			Board[sy][sx].first = 0; // update the start to be empty, 0 = empty
			//printf("%d\n", Board[sx][sy].first);
			//printf("set sx,sy 0\n");
			return true;
		}
};

#endif
