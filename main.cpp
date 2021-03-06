#include "game.h"


using namespace std;

int main(){
  GameBoard myBoard;
  bool running = true;
  string move;
  string space1;
  string space2;
  string delim = "-";
  bool valid = false;
  int current1;
  int current2;
  int next1;
  int next2;
  tuple<int, int>current = make_tuple(0, 0);
  tuple<int, int>next = make_tuple(0, 0);

  cout << "\n\n\nQuick explanation of how to input moves: put the name of the space the piece is on \nfirst and the space you want to move to second.  Examples: d8-d6 or h7-h5\nMake sure everything is lowercase and you seperate the spaces with dashes\n\n\n" << endl;
  while(running){
    //white's turn

    bool whiteCorrectInputAndValid = false;
    myBoard.printBoard(myBoard.getBoard());
    while(!whiteCorrectInputAndValid){
      myBoard.setTemp(myBoard.getBoard()); //refresh temp board
      valid = false;
      while(!valid){
        valid = true;

        cout << "White, please select a move" << endl;
        cin >> move;
        if(move.find(delim)  == -1){
          valid = false;
        }

        space1 = move.substr(0, move.find(delim));
        space2 = move.substr(move.find(delim)+1, move.length());

        if(space1.length() != 2  || space2.length() != 2){
          valid = false;
        }
        if(space1.front() < 97 ||  space1.front() > 104){
          valid = false;
        }
        if(space2.front() < 97 ||  space2.front() > 104){
          valid = false;
        }
        if(space1.back() < 49 || space1.back() > 56){
          valid = false;
        }
        if(space2.back() < 49 || space2.back() > 56){
          valid = false;
        }
        if(space1 == space2){
          valid = false;
        }
        if(valid == false){
          cout << "Invalid Move." << endl;
        }
      }
      switch(space1.front()){
        case 'a': current2 = 0; break;
        case 'b': current2 = 1; break;
        case 'c': current2 = 2; break;
        case 'd': current2 = 3; break;
        case 'e': current2 = 4; break;
        case 'f': current2 = 5; break;
        case 'g': current2 = 6; break;
        case 'h': current2 = 7; break;
      }

      switch(space1.back()){
        case '1': current1 = 7; break;
        case '2': current1 = 6; break;
        case '3': current1 = 5; break;
        case '4': current1 = 4; break;
        case '5': current1 = 3; break;
        case '6': current1 = 2; break;
        case '7': current1 = 1; break;
        case '8': current1 = 0; break;
      }

      switch(space2.front()){
        case 'a': next2 = 0; break;
        case 'b': next2 = 1; break;
        case 'c': next2 = 2; break;
        case 'd': next2 = 3; break;
        case 'e': next2 = 4; break;
        case 'f': next2 = 5; break;
        case 'g': next2 = 6; break;
        case 'h': next2 = 7; break;
      }

      switch(space2.back()){
        case '1': next1 = 7; break;
        case '2': next1 = 6; break;
        case '3': next1 = 5; break;
        case '4': next1 = 4; break;
        case '5': next1 = 3; break;
        case '6': next1 = 2; break;
        case '7': next1 = 1; break;
        case '8': next1 = 0; break;
      }
      current = make_tuple(current1, current2);
      next = make_tuple(next1, next2);
      whiteCorrectInputAndValid = myBoard.isValidMove(current, next, myBoard.getBoard());
      
      if(whiteCorrectInputAndValid){
        myBoard.setTemp( myBoard.modBoard(current, next, myBoard.getTemp(), 1));
        if(!myBoard.inCheck(0, myBoard.getTemp())){
          myBoard.temp[current1][current2] = myBoard.board[current1][current2]; //bugfix
          myBoard.setBoard(myBoard.modBoard(current, next, myBoard.getTemp(), 0));
          
        }
        else{
          whiteCorrectInputAndValid = false;
        }

      }
    }
    //Black's turn
    myBoard.printBoard(myBoard.getBoard());

    if(myBoard.checkMate(myBoard.getBoard(), 1)){
        cout << "White Wins!"<<endl;
        exit(0);
    }

    bool blackCorrectInputAndValid = false;
    while(!blackCorrectInputAndValid){
    myBoard.setTemp(myBoard.getBoard()); //refresh temp board
    valid = false;
      while(!valid){
        valid = true;
        cout << "Black, please select a move" << endl;
        cin >> move;
        if(move.find(delim)  == -1){
          valid = false;
        }
        space1 = move.substr(0, move.find(delim));
        space2 = move.substr(move.find(delim)+1, move.length());

        if(space1.length() != 2  || space2.length() != 2){
          valid = false;
        }
        if(space1.front() < 97 ||  space1.front() > 104){
          valid = false;
        }
        if(space2.front() < 97 ||  space2.front() > 104){
          valid = false;
        }
        if(space1.back() < 49 || space1.back() > 56){
          valid = false;
        }
        if(space2.back() < 49 || space2.back() > 56){
          valid = false;
        }
        if(space1 == space2){
          valid = false;
        }
        if(valid == false){
          cout << "The move you have selected in not valid, please input a different move." << endl;
        }
      }

      switch(space1.front()){
        case 'a': current2 = 0; break;
        case 'b': current2 = 1; break;
        case 'c': current2 = 2; break;
        case 'd': current2 = 3; break;
        case 'e': current2 = 4; break;
        case 'f': current2 = 5; break;
        case 'g': current2 = 6; break;
        case 'h': current2 = 7; break;
      }

      switch(space1.back()){
        case '1': current1 = 7; break;
        case '2': current1 = 6; break;
        case '3': current1 = 5; break;
        case '4': current1 = 4; break;
        case '5': current1 = 3; break;
        case '6': current1 = 2; break;
        case '7': current1 = 1; break;
        case '8': current1 = 0; break;
      }

      switch(space2.front()){
        case 'a': next2 = 0; break;
        case 'b': next2 = 1; break;
        case 'c': next2 = 2; break;
        case 'd': next2 = 3; break;
        case 'e': next2 = 4; break;
        case 'f': next2 = 5; break;
        case 'g': next2 = 6; break;
        case 'h': next2 = 7; break;
      }

      switch(space2.back()){
        case '1': next1 = 7; break;
        case '2': next1 = 6; break;
        case '3': next1 = 5; break;
        case '4': next1 = 4; break;
        case '5': next1 = 3; break;
        case '6': next1 = 2; break;
        case '7': next1 = 1; break;
        case '8': next1 = 0; break;
      }

      current = make_tuple(current1, current2);
      next = make_tuple(next1, next2);
      blackCorrectInputAndValid = myBoard.isValidMove(current, next, myBoard.getBoard());
      
      if(blackCorrectInputAndValid){
        myBoard.setTemp( myBoard.modBoard(current, next, myBoard.getTemp(), 1));
        if(!myBoard.inCheck(1, myBoard.getTemp())){
          myBoard.temp[current1][current2] = myBoard.board[current1][current2]; //bugfix
          myBoard.setBoard(myBoard.modBoard(current, next, myBoard.getTemp(), 0));
        }
        else{
          blackCorrectInputAndValid = false;
        }

      }
    }
    if(myBoard.checkMate(myBoard.getBoard(), 0)){
        cout << "Black Wins!"<<endl;
        exit(0);
    }
    

  }
}
