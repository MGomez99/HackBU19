#include "game.h"

using namespace game;
GameBoard(){

};
bool isValidMove(int piece, std::tuple<int, int> position){
    switch (piece % 6)
    { //@TODO
        case 0:
            /* pawn */
            break;
        case 1:
            /* rook */
            break;
        case 2:
            /* knight */
            break;
        case 3:
            /* bishop */
            break;
        case 4:
            /* queen */
            break;
        case 5:
            /* king */
            break;
            
        default:
            break;
    }
}

bool isInCheck(int turn){

}
bool gameOver(){
    
}
void move(int piece, std::tuple<int, int> start, std::tuple<int, int> end, vect2d board){
    board[std::get<0>(start)][std::get<1>(start)] = empty;
    board[std::get<0>(end)][std::get<1>(end)] = piece;

}
void printBoard(vect2d board, int turn){
    
    for(int i = 0; i < 8; i++){
        std::cout << "|\t";
        for(int j = 0; i < 8; i++){
            std::cout << PieceNames[board[i][j]] << "\t";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "Current turn: ";
    if(turn == 0){std::cout << "White";}
    else{std::cout << "Black";}
}