#include <cstdlib>
#include <iostream>
#include "game.h"


using namespace std;

int main(){
  bool running = true;
  string move;
  string space1;
  string space2;
  string delim = "-";
  bool valid = false;
  int current[2];
  int new[2];

  cout << "\n\n\nQuick explanation of how to input moves: put the name of the space the piece is on \nfirst and the space you want to move to second.  Examples: d8-d6 or h7-h5\nMake sure everything is lowercase and you seperate the spaces with dashes\n\n\n" << endl;
  while(running){
    //white's turn
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
        cout << "The move you have selected in not valid, please input a different move." << endl;
      }
    }


    //Black's turn
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
  }
}
