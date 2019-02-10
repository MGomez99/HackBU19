#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <tuple>

#ifndef GAME_1
#define GAME_1
#define vect2d std::vector <std::vector<int>>

enum Pieces {emptyS = -1, pawnW, knightW, bishopW, rookW, queenW, kingW, pawnB, knightB, bishopB, rookB, queenB, kingB};
    /*  White < 6 ; Black >= 6
        Pawn = 0/6, Rook = 1/7, Knight = 2/8, Bishop = 3/9, Queen = 4/10, King = 5/12
    */
//     main::main()
namespace game{
    class GameBoard{
        private:
            vect2d board{
                {rookB, knightB, bishopB, queenB, kingB, bishopB, knightB, rookB},
                {pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB, pawnB},
                {emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS},
                {emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS},
                {emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS},
                {emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS, emptyS},
                {pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW, pawnW},
                {rookW, knightW, bishopW, queenW, kingW, bishopW, knightW, rookW} };
        public:
            GameBoard();
            std::tuple<int, int, int> bCastle = std::make_tuple(1, 1 , 1); //hasn't moved
            std::tuple<int, int, int> wCastle = std::make_tuple(1, 1 , 1); //hasn't moved
            std::tuple<int, int> enPassant = std::make_tuple(-1, -1);
            bool isValidMove(std::tuple<int, int> start, std::tuple<int, int> end, vect2d board);
            bool inCheck(int turn, vect2d board); //is the player in check; 0 = white | 1 = black
            bool checkMate(std::vector<std::vector<int>> board, int player); //check for c
            vect2d modBoard(std::tuple<int, int> start, std::tuple<int, int> end, vect2d board); //modifies board and returns it
            vect2d getBoard(){ return this->board;}
            void setBoard(vect2d newBoard){this->board = newBoard;}
            void printBoard(vect2d board, int turn);
            std::vector<std::tuple<int, int>>possibleMoves(std::tuple<int, int> position, vect2d board);
            std::vector<std::tuple<int, int, int, int>> allPossibleMoves(vect2d board, int turn);
            bool isInBoard(int x, int y);
            int teamCheck(int team, int x, int y,vect2d board);
            bool isAttacked(std::vector<std::vector<int>> board, int x, int y);
            std::string getPieceName(int i);

    };
}

#endif
