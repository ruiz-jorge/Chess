#ifndef __CHECKER_MOVE_HPP__
#define __CHECKER_MOVE_HPP__

#include "MoveInterface.hpp"
#include <utility>
#include <vector>
#include "Bishop.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"

class CheckerMove : public MoveInterface {
	public:
		bool move(std::vector<std::vector<std::pair<int, int>>> &Board, std::vector<Piece*> v_p, int sy, int sx, int dy, int dx){
			
			if(abs(dx - sx) != abs(dy - sy)){ 
				//printf("Invalid move\n");
				return false;
			}
		
			if(!(sx >= 0 && sx <= 7 && sy >= 0 && sy <= 7 && dx >= 0 && dx <= 7 && dy >= 0 && dy <= 7)){
				//printf("not in range\n");
				return false;
			}

			if(abs(dx - sx) == 2) { // jumping
				int midx = (sx + dx) / 2;
				int midy = (sy + dy) / 2;
					if(Board[midy][midx].first == 0){
						return false; // can't jump over empty
					}
					else if(Board[midy][midx].first == Board[sy][sx].first){
						return false; // can't jump over your piece
					}
					else{
						v_p[Board[midy][midx].second]->setStatus(false);
						Board[midy][midx].first = 0;
					}
			}
			else if(abs(dx - sx) == 1){ // moving to the upper left
				if(Board[dy][dx].first != 0){
					return false;
				}
			}
			else{ //jumping over >2 spots
				return false;
			}	
			//printf("1");		
			//printf("2");	
			
			//printf("\n[dx][dy]: ");
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
