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
        getline(cin,line);
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
        else if(line.substr(0,2)=="go"){
            int wtime=1e9, btime=1e9; //time left for white in milliseconds and time left for black in milliseconds
            if(line.find("wtime")!=string::npos){
                stringstream s(line.substr(line.find("wtime")+6));
                s>>wtime;
            }
            if(line.find("btime")!=string::npos){
                stringstream s(line.substr(line.find("btime")+6));
                s>>btime;
            }
            Move bestmove=bestMove(board); //any debug prints with an endline at the end is fine in the bestMove function, as long as it does not contain the string bestmove
            makeMove(board,bestmove);
            cout<<"bestmove "<<moveToUSI(bestmove)<<endl;
        }
        else{
            makeMove(board,USItoMove(line,board));
        }
    }
}
