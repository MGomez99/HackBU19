#include "game.h"

using namespace game;
bool isInBoard(int x, int y){
    if(x < 8 && x >=0 ){
        if(y < 8 && y >=0 ){
            return true;
        }
    }
    return false;
}
int teamCheck(int team, int x, int y,vect2d board){
    int piece = board[x][y];
    if(piece != -1){
        if(team == 0 && piece > 5){
            return 1;
        }
        else if(team == 0 && piece <= 5)
        {
            return 0;
        }
        if(team == 1 && piece > 5){
            return 0;
        }
        else if(team == 1 && piece <= 5)
        {
            return 1;
        }
        
    }
    return -1;
}
bool isAttacked(std::vector<std::vector<int>> board, int x, int y){
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
std::string getPieceName(int i){
    std::vector<std::string> PieceNames = {"pawnW", "knightW", "bishopW", "rookW", "queenW", "kingW", "pawnB", "knightB", "bishopB", "rookB", "queenB", "kingB"};
    return PieceNames[i];
}
std::vector<std::tuple<int, int>> GameBoard::possibleMoves(std::tuple<int, int> position, vect2d board){
    int x = std::get<0>(position);
    int y = std::get<1>(position);
    int piece = board[x][y]; //position must be <row, column>
    int team = 0; //white team
    if(piece > 5){
        team = 1;
    }
    std::tuple<int, int> move;
    std::vector<std::tuple<int, int>> allValidMoves;
    switch (piece % 6)
    {  
        case 0:
            /* pawn */
            //vertical moves
            if(piece == 0 && x == 6){ //pawn is white
                {
                    move = std::make_tuple(x-1, y);
                    if(teamCheck( team,std::get<0>(move), std::get<1>(move), board) == -1){ //Space up one row is clear
                        allValidMoves.push_back(move);
                        if(x == 6){ //is in starting row
                            move = std::make_tuple(x-2, y);
                            if((teamCheck(team,std::get<0>(move), std::get<1>(move), board) == -1)){ //Spaces up one and two row is clear
                                allValidMoves.push_back(move);
                            }
                        }
                    }
                    
                }
            }
            else if(piece == 6 ) //same as white pawn, but for black
            {
                move = std::make_tuple(x+1, y);
                    if(teamCheck( team,std::get<0>(move), std::get<1>(move), board) == -1){ //Space down one row is clear
                        allValidMoves.push_back(move);
                        if(x == 1){ //is in starting row
                            move = std::make_tuple(x+2, y);
                            if((teamCheck(team,std::get<0>(move), std::get<1>(move), board) == -1)){ //Spaces down one and two row is clear
                                allValidMoves.push_back(move);
                            }
                        }
                    }
            }
            //Capture moves
            if(team == 0)
            { //white pawn
                move = std::make_tuple(x-1, y+1);
                if(isInBoard(std::get<0>(move), std::get<1>(move)))
                {
                    if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) == 1){
                        allValidMoves.push_back(move);
                    }
                    else if(std::get<0>(enPassant) == x && std::get<1>(enPassant)-1 ==y) {
                        allValidMoves.push_back(move);
                    }
                }
                move = std::make_tuple(x-1, y-1);
                if(isInBoard(std::get<0>(move), std::get<1>(move)))
                {
                    if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) == 1){
                        allValidMoves.push_back(move);
                    }
                    else if(std::get<0>(enPassant) == x && std::get<1>(enPassant)+1 ==y) {
                        allValidMoves.push_back(move);
                    }
                }
            }
            if(team == 1)
            { //black pawn
                move = std::make_tuple(x+1, y+1);
                if(isInBoard(std::get<0>(move), std::get<1>(move)))
                {
                    if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) == 1){
                        allValidMoves.push_back(move);
                    }
                    else if(std::get<0>(enPassant) == x && std::get<1>(enPassant)-1 ==y) {
                        allValidMoves.push_back(move);
                    }

                }
                move = std::make_tuple(x+1, y-1);
                if(isInBoard(std::get<0>(move), std::get<1>(move)))
                {
                    if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) == 1){
                        allValidMoves.push_back(move);
                    }
                    else if(std::get<0>(enPassant) == x && std::get<1>(enPassant)+1 ==y) {
                        allValidMoves.push_back(move);
                    }
                }
            }

            break;
        case 1:
            /* knight */
            move = std::make_tuple(x+1, y+2);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x+2, y+1);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x+2, y-1);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x+1, y-2);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x-1, y-2);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x-2, y-1);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x-2, y+1);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            move = std::make_tuple(x-1, y+2);
            if(isInBoard(std::get<0>(move), std::get<1>(move))){
                if(teamCheck(team,std::get<0>(move), std::get<1>(move), board) != 0){ //move will land on enemy piece or is empty
                    allValidMoves.push_back(move);
                }
            }
            break;
        
        case 2:
            /* bishop */
            for(int i = 0; i < 8; i++){
                if(isInBoard(x+i, y+i)){
                    move = std::make_tuple(x+i, y+i);
                    if(teamCheck(team, x+i, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y+i)){
                    move = std::make_tuple(x-i, y+i);
                    if(teamCheck(team, x-i, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x+i, y-i)){
                    move = std::make_tuple(x+i, y-i);
                    if(teamCheck(team, x+i, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y-i)){
                    move = std::make_tuple(x-i, y-i);
                    if(teamCheck(team, x-i, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
            }
            break;
        case 3:
            /* rook */
            //check +x -x directions
            for(int i = 1; i < 8; i++)
            {
                if(isInBoard(x + i, y)){
                    move = std::make_tuple(x+i, y);
                    if(teamCheck(team, x+i, y, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y)){
                    move = std::make_tuple(x-i, y);
                    if(teamCheck(team, x-i, y, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x, y+i)){
                    move = std::make_tuple(x, y+i);
                    if(teamCheck(team, x, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x, y-i)){
                    move = std::make_tuple(x, y-i);
                    if(teamCheck(team, x, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
            }
            
            break;
        case 4:
            /* queen */
            for(int i = 1; i < 8; i++) //rook move style
            {
                if(isInBoard(x + i, y)){
                    move = std::make_tuple(x+i, y);
                    if(teamCheck(team, x+i, y, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y)){
                    move = std::make_tuple(x-i, y);
                    if(teamCheck(team, x-i, y, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x, y+i)){
                    move = std::make_tuple(x, y+i);
                    if(teamCheck(team, x, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x, y-i)){
                    move = std::make_tuple(x, y-i);
                    if(teamCheck(team, x, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
            }
            for(int i = 0; i < 8; i++) //bishop move style
            {
                if(isInBoard(x+i, y+i)){
                    move = std::make_tuple(x+i, y+i);
                    if(teamCheck(team, x+i, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y+i)){
                    move = std::make_tuple(x-i, y+i);
                    if(teamCheck(team, x-i, y+i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x+i, y-i)){
                    move = std::make_tuple(x+i, y-i);
                    if(teamCheck(team, x+i, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
                if(isInBoard(x-i, y-i)){
                    move = std::make_tuple(x-i, y-i);
                    if(teamCheck(team, x-i, y-i, board) != 0){ //move will land on enemy piece or is empty
                        allValidMoves.push_back(move);
                    }
                }
            }
            break;
        case 5:
            /* king */
            //Castling Moves
            //Left White Castle
            move = std::make_tuple(7, 0);
            if(std::get<0>(wCastle) == 1 && std::get<1>(wCastle) == 1 )
            {//left rook and white king hasn't moved
                bool canCastle = true;
                for(int i = 2; i < 5; i++){
                    if(isAttacked(board, x, i)){
                        canCastle = false;
                    }
                }
                if(canCastle){
                    allValidMoves.push_back(move);
                }
            }
            //Right White Castle
            move = std::make_tuple(7, 6);
            if(std::get<1>(wCastle) == 1 && std::get<2>(wCastle) == 1 )
            {//right rook and white king hasn't moved
                bool canCastle = true;
                for(int i = 4; i < 7; i++){
                    if(isAttacked(board, x, i)){
                        canCastle = false;
                    }
                }
                if(canCastle){
                    allValidMoves.push_back(move);
                }
            }

            //Left Black Castle
            move = std::make_tuple(0, 0);
            if(std::get<0>(bCastle) == 1 && std::get<1>(bCastle) == 1 )
            {//left rook and black king hasn't moved
                bool canCastle = true;
                for(int i = 1; i < 4; i++){
                    if(isAttacked(board, x, i)){
                        canCastle = false;
                    }
                }
                if(canCastle){
                    allValidMoves.push_back(move);
                }
            }
            //Right Black Castle
            move = std::make_tuple(0, 7);
            if(std::get<0>(bCastle) == 1 && std::get<1>(bCastle) == 1 )
            {//right rook and black king hasn't moved
                bool canCastle = true;
                for(int i = 3; i < 6; i++){
                    if(isAttacked(board, x, i)){
                        canCastle = false;
                    }
                }
                if(canCastle){
                    allValidMoves.push_back(move);
                }
            }

            break;
        default:
            std::cout << "fatal error, wrong piece?." <<std::endl;
    }
    
    return allValidMoves;
}

bool GameBoard::isInCheck(int turn, vect2d board){
    return true;
}
bool GameBoard::checkmate(){
    return true;
}
vect2d GameBoard::modBoard(int piece, std::tuple<int, int> start, std::tuple<int, int> end, vect2d board){
    board[std::get<0>(start)][std::get<1>(start)] = empty;
    board[std::get<0>(end)][std::get<1>(end)] = piece;
    //en-Passant check
    if(piece % 6 == 0){
       if(std::get<1>(start) == std::get<0>(end) +1 || std::get<1>(start) == std::get<0>(end) - 1){ //if a pawn is moving  to a different coloumn
            if((std::get<1>(enPassant) == std::get<1>(end)) && (std::get<0>(enPassant) == std::get<0>(start))){
                board[std::get<0>(enPassant)][std::get<1>(enPassant)] = empty;
                enPassant = std::make_tuple(-1, -1);
            }
       }
       if(std::get<0>(start) + 2 == std::get<0>(end) ||std::get<0>(start) - 2 == std::get<0>(end)){
           enPassant = end;
       }
       //Check Promotion @TODO
    }
    else{ //make sure to set enPassant to not active
        enPassant = std::make_tuple(-1, -1);
    }
    /******************************** Castle Logic *********************************/
    if(piece % 6 == 5){
        if(piece < 6){
            wCastle = std::make_tuple(1, 0, 1);
        }
        else{
            bCastle = std::make_tuple(1, 0, 1);
        }
    }

    if(piece == 3){
        if(std::get<0>(start) == 7 &&std::get<1>(start) == 0){
            std::tuple<int, int, int> temp = std::make_tuple(0, std::get<1>(wCastle), std::get<2>(wCastle));
            wCastle = temp;
        }
        else if(std::get<0>(start) == 7 && std::get<1>(start) == 7){
            std::tuple<int, int, int> temp = std::make_tuple(std::get<0>(wCastle), std::get<1>(wCastle), 0);
            wCastle = temp;
        }
    }
     if(piece == 9){
        if(std::get<0>(start) == 0 &&std::get<1>(start) == 0){
            std::tuple<int, int, int> temp = std::make_tuple(0, std::get<1>(bCastle), std::get<2>(bCastle));
            bCastle = temp;
        }
        else if(std::get<0>(start) == 0 &&std::get<1>(start) == 7){
            std::tuple<int, int, int> temp = std::make_tuple(std::get<0>(bCastle), std::get<1>(bCastle), 0);
            bCastle = temp;
        }
    }
    /**************************************************************************************/
    //King Castle Moves
    if(piece % 6 == 5){
        
    }
    return board;
}

void printBoard(vect2d board, int turn){
    
    for(int i = 0; i < 8; i++){
        std::cout << "|\t";
        for(int j = 0; i < 8; i++){
            std::cout << getPieceName(board[i][j]) << "\t";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "Current turn: ";
    if(turn == 0){std::cout << "White";}
    else{std::cout << "Black";}
}