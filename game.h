#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <tuple>

#ifndef GAME_1
#define GAME_1
#define vect2d std::vector <std::vector<int>>

enum Pieces {empty = -1, pawnW, rookW, knightW, bishopW, queenW, kingW, pawnB, rookB, knightB, bishopB, queenB, kingB};
    /*  White < 6 ; Black >= 6
        Pawn = 0/6, Rook = 1/7, Knight = 2/8, Bishop = 3/9, Queen = 4/10, King = 5/12
    */
char const *PieceNames[12] = {"pawnW", "rookW", "knightW", "bishopW", "queenW", "kingW", "pawnB", "rookB", "knightB", "bishopB", "queenB", "kingB"};

namespace game{
    class gameboard{
        private:
            vect2d board{
                {rookB, knightB, bishopB, queenB, kingB, bishopB, knightB, rookB},
                {pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {empty, empty, empty, empty, empty, empty, empty, empty},
                {pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW},
                {rookW, knightW, bishopW, queenW, kingW, bishopW, knightW, rookW} };
        public:
            bool isValidMove(int piece, std::tuple<int> position, vect2d board);
            bool isInCheck(int turn, vect2d board); //is the player in check; 0 = white | 1 = black
            bool gameOver(); //is the game won 
            void move(int piece, std::tuple<int, int> start, std::tuple<int, int> end, vect2d board); //move piece
            vect2d getBoard(){ return this->board;}
            void printBoard(vect2d board, int turn);


    };
}

#endif
