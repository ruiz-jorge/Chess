#include "Checkers.hpp"

void Checkers::makePieces(){
    int x=0,y=1;
    for (int i=0; i<12;i++){
        Piece* p=new Checker("C");
        pieces.push_back(p);
        pieces[i]->setBehavior(new CheckerMove,"Checker");
        board[x][y].first=1;
        board[x][y].second=i;
        if(i==3||i==7)x++;
        y+=2;
        if (y==9)y=0;
        else if(y==8)y=1;
    }
    x=5;
    for (int i=0; i<12;i++){
        Piece* p=new Checker("c");
        pieces.push_back(p);
        pieces[i+12]->setBehavior(new CheckerMove,"Checker");
        board[x][y].first=2;
        board[x][y].second=i+12;
        if(i==3||i==7)x++;
        y+=2;
        if (y==9)y=0;
        else if(y==8)y=1;
    }
}

void Checkers::fillBoard(){
    std::vector<std::pair<int,int>> v;
    for (int i=0; i<8; i++){
        std::pair<int,int>space(0,0);
        v.push_back(space);
    }
    for (int i=0; i<8; i++){
        board.push_back(v);
    }
}

bool Checkers::move_piece(int sx, int sy, int dx, int dy){
    if (abs(sx-dx)!=abs(sy-dy))return false;
    if (abs(sx-dx)>2)return false;
    return pieces[board[sx][sy].second]->move(board,pieces,sx,sy,dx,dy);
}

void Checkers::player_turn(int num){
    int sx,sy,dx,dy;
    int startingpieces=pieces.size();
    getStartL(sx,sy);
    getEndL(dx,dy);
    if (board[sx][sy].first!=num){
        std::cout<<"Invalid starting location selected.\n";
        player_turn(num);
    }
    if (sx<0||sx>7||dx<0||dx>7||sy<0||sy>7||dy<0||dy>7){
        std::cout<<"Invalid starting location selected.\n";
        player_turn(num);
    }
    if (move_piece(sx,sy,dx,dy)==false){
        std::cout<<"Invalid input\n";
        player_turn(num);
    }
    if (startingpieces>pieces.size()){
        startingpieces=pieces.size();
        
        if ((board[dx+1][dy+1].first!=0&&board[dx+1][dy+1].first!=num&&board[dx+2][dy+2].first==0)||
                (board[dx+1][dy-1].first!=0&&board[dx+1][dy-1].first!=num&&board[dx+2][dy-2].first==0)||
                (board[dx-1][dy+1].first!=0&&board[dx-1][dy+1].first!=num&&board[dx-2][dy+2].first==0)||
                board[dx-1][dy-1].first!=0&&board[dx-1][dy-1].first!=num&&board[dx-2][dy-2].first==0){
        nextMove(dx,dy);}//test to see if possible next jump
    }
    
}
void Checkers::getStartL(int &sx, int &sy){
    std::cout<<"Enter the row of the piece you wish to move:";
    std::cin>>sx;
    std::cout<<"Enter the column of the piece you wish to move:";
    std::cin>>sy;
}
void Checkers::getEndL(int &dx, int &dy){
    std::cout<<"Enter the row where you wish to move:";
    std::cin>>dx;
    std::cout<<"Enter the column where you wish to move:";
    std::cin>>dy;
}
void Checkers::nextMove(int sx, int sy){
    print_board();
    int dx,dy;
    int startingpieces=pieces.size();
    std::cout<<"Another piece can be jumped, please enter the row where you want to jump to:";
    std::cin>>dx;
    std::cout<<"Please enter the column were you want to jump to:";
    std::cin>>dy;
    if (move_piece(sx,sy,dx,dy)==false){
        std::cout<<"Invalid input\n";
        nextMove(sx,sy);
    }
    if (startingpieces>pieces.size()){
        startingpieces=pieces.size();
        
        if ((board[dx+1][dy+1].first!=0&&board[dx+1][dy+1].first!=board[sx][sy].first&&board[dx+2][dy+2].first==0)||
                (board[dx+1][dy-1].first!=0&&board[dx+1][dy-1].first!=board[sx][sy].first&&board[dx+2][dy-2].first==0)||
                (board[dx-1][dy+1].first!=0&&board[dx-1][dy+1].first!=board[sx][sy].first&&board[dx-2][dy+2].first==0)||(
                board[dx-1][dy-1].first!=0&&board[dx-1][dy-1].first!=board[sx][sy].first&&board[dx-2][dy-2].first==0)){
        nextMove(dx,dy);}//test to see if possible next jump
    }
}
void Checkers::play_game(){
    while(check_win()!=true){
        int track;
        for (int i=0; i<player_status.size();i++){
            std::cout<<"Press a key to play turn, enter 2 to give up:";//give option to quit game
            std::cin>>track;
            if (track==2){elimPlayer(i);
	    i=player_status.size();
	    }
            else{
            print_board();
            player_turn(i+1);
            checkPlayers();
            if (check_win()==true)i=player_status.size();}
        }
        
       
    }
	for (int i=0; i<player_status.size();i++){
	if (player_status[i]==true)std::cout<<"Congratulations "<<player_name[i]<<std::endl;
	}
}
void Checkers::checkPlayers(){
    
    for (int i=0;i<player_status.size();i++){
        bool stat=false;
        for (int j=i*12;j<(i+1)*12;j++){
            if (pieces[j]->returnStatus()==true)stat=true;
        }
        if (stat==false)
        elimPlayer(i);
    }
}
void Checkers::elimPlayer(int num){
    if (num>=0&&num<player_status.size());
    player_status[num]=false;
}
