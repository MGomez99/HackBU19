#include "game.h"

using namespace game;

std::string getPieceName(int i){
    std::vector<std::string> PieceNames = {"pawnW", "knightW", "bishopW", "rookW", "queenW", "kingW", "pawnB", "knightB", "bishopB", "rookB", "queenB", "kingB"};
    return PieceNames[i];
}
std::vector<std::tuple<int, int>> isValidMove(std::tuple<int, int> position, vect2d board){
    int piece = board[std::get<0>(position)][std::get<1>(position)]; //position must be <row, column>
    std::vector<std::tuple<int, int>> allValidMoves;
    switch (piece % 6)
    {  
        case 0:
            /* pawn */

            break;
        case 1:
            /* knight */
            
            break;
        case 2:
            /* bishop */
            break;
        case 3:
            /* rook */
            break;
        case 4:
            /* queen */
            break;
        case 5:
            /* king */
            break;
        default:
            std::cout << "fatal error, wrong piece." <<std::endl;
    }
    
    return allValidMoves;
}

bool isInCheck(int turn, vect2d board){
    return true;
}
bool checkmate(){
    return true;
}
vect2d modBoard(int piece, std::tuple<int, int> start, std::tuple<int, int> end, vect2d board){
    board[std::get<0>(start)][std::get<1>(start)] = empty;
    board[std::get<0>(end)][std::get<1>(end)] = piece;
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