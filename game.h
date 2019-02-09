#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

#ifndef GAME_1
#define GAME_1
enum Pieces {empty = -1, pawnW, rookW, knightW, bishopW, queenW, kingW, pawnB, rookB, knightB, bishopB, queenB, kingB};
    /*  White < 6 ; Black >= 6
        Pawn = 0/6, Rook = 1/7, Knight = 2/8, Bishop = 3/9, Queen = 4/10, King = 5/12
    */
namespace game{
    class gameboard{
        private:
            std::vector <std::vector<int>> gameboard{
                {rookB, knightB, bishopB, queenB, kingB, bishopB, knightB, rookB},
                {pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW},
                {rookW, knightW, bishopW, queenW, kingW, bishopW, knightW, rookW} };
        public:
            bool isValidMove(int piece, std::tuple<int> position);
            bool isInCheck(int turn); //is the player in check; 0 = white | 1 = black
            bool gameOver(); //is the game won
            void move(int piece, std::tuple<int, int> move); //move piece
            std::vector <std::vector<int>> getBoard(){ return this->gameboard;}


};
}

#endif
