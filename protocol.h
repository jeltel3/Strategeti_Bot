#include<bits/stdc++.h>
using namespace std;
struct position{
};
struct Move{
};
void initializeBoard(position& board);
void makeMove(position& board,Move m);
string moveToUSI(Move m);
Move USItoMove(string s,position& board);
int main(){
    position board;
    while(true){
        string line;
        cin>>line;
        if(line=="quit"){
            break;
        }
        else if(line=="usinewgame"){
            initializeBoard(board);
            cout<<"usiok"<<endl;
        }
        else if(line=="isready"){
            cout<<"readyok"<<endl;
        }
        else if(line=="go"){
            Move bestmove=bestMove(board);
            makeMove(board,bestmove);
            cout<<moveToUSI(bestmove)<<endl;
        }
        else{
            makeMove(board,USItoMove(line,board));
        }
    }
}
