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
            break;
        default:
            std::cout << "fatal error, wrong piece." <<std::endl;
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
    }
    else{
        enPassant = std::make_tuple(-1, -1);
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