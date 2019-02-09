#include "game.h"

using namespace game;

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
void move(int piece, std::tuple<int, int> move, vect2d board){

}
void printBoard(vect2d board){
    
    for(int i = 7; i >= 0; i++){
        std::cout << "|\t";
        for(int j = 0; i < 8; i++)
        {
            
        }
        std::cout << "|\t" << std::endl;
    }
}