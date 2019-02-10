#include "game.h"
#ifdef LARK
using namespace std;


float minimax(vector<vector<int>> board, bool maximizingPlayer, int turn, int depth){
  //terminal node
  if(checkMate(board)){
    if(maximizingPlayer) return 1000000;
    else return -1000000;
  }
  if(depth = 0){
    float value = INT_MIN;
    for(tuple<int, int, int, int> move : possibleMoves(board, turn)){
      if(maximizingPlayer&&turn==0 || !maximizingPlayer&&turn==1){//if max player is white
        value = max(value, boardEval(board, turn));
      }
      else{ //if max player is black
        value = max(value, -1*boardEval(board, turn));
      }
    }
    if(maximizingPlayer) return evalBoard(board);
    else return -1*evalBoard(board);
  }
  if(maximizingPlayer){
    float value = INT_MIN;
    for(tuple<int, int, int, int> move : possibleMoves(board, turn)){
      value = max(value, minimax(modBoard(turn, move, board), false, (turn+1)%2, depth-1));
    }
    return value;
  }
  else{
    float value = INT_MAX;
    for(tuple<int, int, int, int> move : possibleMoves(board, turn)){
      value = min(value, minimax(modBoard(turn, move, board), true, (turn+1)%2, depth-1));
    }
    return value;
  }
}
tuple<int, int, int, int> bestMove(board, turn, depth){
  int value = INT_MIN;
  tuple<int, int, int, int> movechoice;
  for(tuple<int, int, int, int> move : possibleMoves(board, turn)){
    if(minimax(modBoard(turn, move, board), true, turn, depth) > value){
      value = minimax(modBoard(turn, move, board), true, turn, depth);
      movechoice = move;
    }
  }
  return movechoice;
}

float boardEval(vector<vector<int>> board){
  float value = 0;
  //counting material
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j]==0){ //white pawn
        value += 1;
      }
      if(board[i][j]==1){ //white knight
        value += 3;
      }
      if(board[i][j]==2){ //white bishop
        value += 3.18;
      }
      if(board[i][j]==3){ //white rook
        value += 4.78;
      }
      if(board[i][j]==4){ //white queen
        value += 9.32;
      }
      if(board[i][j]==5){ //white king
        value += 2;
      }
      if(board[i][j]==6){ //black pawn
        value -= 1;
      }
      if(board[i][j]==7){ //black knight
        value -= 3;
      }
      if(board[i][j]==8){ //black bishop
        value -= 3.18;
      }
      if(board[i][j]==9){ //black rook
        value -= 4.78;
      }
      if(board[i][j]==10){ //black queen
        value -= 9.32;
      }
      if(board[i][j]==11){ //black king
        value -= 2;
      }
    }
  }
  return value;
}
bool isAttacked(vector<vector<int>> board, int x, int y){
  //store original piece coords
  int xpos = x;
  int ypos = y;
  //get team
  int team = 0;
  if(board[x][y]>5) team = 1;
  //horizontal

  //backwards on x
  bool prehori = true;
  while(x > -1 && prehori){
    if(board[x][y]==9&&team==0) return true; //attacked by a black rook
    if(board[x][y]==3&&team==1) return true; //attacked by a white rook
    if(board[x][y]==10&&team==0) return true; //attacked by a black queen
    if(board[x][y]==4&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) prehori = false;
    x--;
  }
  x = xpos;
  y = ypos;
  //forwards on x
  bool posthori = true;
  while(x < 8 && posthori){
    if(board[x][y]==9&&team==0) return true; //attacked by a black rook
    if(board[x][y]==3&&team==1) return true; //attacked by a white rook
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) posthori = false;
    x++;
  }
  x = xpos;
  y = ypos;
  //vertical

  //backwards on y
  bool prevert = true;
  while(y > -1 && prevert){
    if(board[x][y]==9&&team==0) return true; //attacked by a black rook
    if(board[x][y]==3&&team==1) return true; //attacked by a white rook
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) prevert = false;
    y--;
  }
  x = xpos;
  y = ypos;
  //forwards on y
  bool postvert = true;
  while(y < 8 && postvert){
    if(board[x][y]==9&&team==0) return true; //attacked by a black rook
    if(board[x][y]==3&&team==1) return true; //attacked by a white rook
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) postvert = false;
    y++;
  }
  x = xpos;
  y = ypos;
  //diagonals
  //diag 1
  bool diag1 = true;
  while(x < 8 && y > -1 && diag1){
    if(board[x][y]==8&&team==0) return true; //attacked by a black bishop
    if(board[x][y]==2&&team==1) return true; //attacked by a white bishop
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) diag1 = false;
    x++;
    y--;
  }
  x = xpos;
  y = ypos;
  //diag 2
  bool diag2 = true;
  while(x < 8 && y < 8 && diag2){
    if(board[x][y]==8&&team==0) return true; //attacked by a black bishop
    if(board[x][y]==2&&team==1) return true; //attacked by a white bishop
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) diag2 = false;
    x++;
    y++;
  }
  x = xpos;
  y = ypos;
  //diag 3
  bool diag3 = true;
  while(x > -1 && y < 8 && diag3){
    if(board[x][y]==8&&team==0) return true; //attacked by a black bishop
    if(board[x][y]==2&&team==1) return true; //attacked by a white bishop
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) diag3 = false;
    x--;
    y++;
  }
  x = xpos;
  y = ypos;
  //diag 4
  bool diag4 = true;
  while(x > -1 && y > -1 && diag4){
    if(board[x][y]==8&&team==0) return true; //attacked by a black bishop
    if(board[x][y]==2&&team==1) return true; //attacked by a white bishop
    if(board[x][y]==9&&team==0) return true; //attacked by a black queen
    if(board[x][y]==3&&team==1) return true; //attacked by a white queen
    if(board[x][y]!=-1) diag4 = false;
    x--;
    y--;
  }
  x = xpos;
  y = ypos;
  //knights
  if(team == 0){ //checking for black knights
    if(board[x-1][y+2]==7||board[x+1][y+2]==7||board[x+2][y+1]==7||board[x+2][y-1]==7||board[x+1][y-2]==7||board[x-1][y-2]==7||board[x-2][y-1]==7||board[x-2][y+1]==7){
      return true;
    }
  }
  else{ //checking for white knights
    if(board[x-1][y+2]==2||board[x+1][y+2]==2||board[x+2][y+1]==2||board[x+2][y-1]==2||board[x+1][y-2]==2||board[x-1][y-2]==2||board[x-2][y-1]==2||board[x-2][y+1]==2){
      return true;
    }
  }
  //pawns
  if(team == 0){ //checking for black pawns
    if(board[x-1][y-1]==6||board[x+1][y-1]==6){
      return true;
    }
  }
  else{ //checking for white pawns
    if(board[x+1][y+1]==0||board[x+1][y+1]==0){
      return true;
    }
  }
  return false;
}
bool isThreatened(){
  //higher level threats, for ai later
}

bool inCheck(vector<vector<int>> board, int player){
  if(player == 0){ //king in question is white
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(board[i][j]==5){
          if(isAttacked(board, i, j)) return true;
        }
      }
    }
  }
  if(player == 1){ //king in question is black
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(board[i][j]==11){
          if(isAttacked(board, i, j)) return true;
        }
      }
    }
  }
  return false;
}
vector<tuple<int, int, int, int>> allPossibleMoves(board, turn){
  vector<tuple<int, int, int, int>> moves;
  if(turn == 0) { //white to play
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(board[i][j]) < 6){
          for(tuple<int, int> t : possibleMoves(make_tuple(i, j), board)){
            moves.push_back(make_tuple(i, j, get<0>(t), get<1>(t)));
          }
        }
      }
    }
  }
  else{ //black to play
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(board[i][j]) > 5){
          for(tuple<int, int> t : possibleMoves(make_tuple(i, j), board)){
            moves.push_back(make_tuple(i, j, get<0>(t), get<1>(t)));
          }
        }
      }
    }
  }
  return moves;
}
bool checkMate(vector<vector<int>> board, int player){
  for(tuple<int, int, int, int> move : allPossibleMoves(board, player)) {
    if(!inCheck(modBoard(board, move), player)) return false;
  }
  return true;
}
#endif