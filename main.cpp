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
  int next[2];

  cout << "\n\n\nQuick explanation of how to input moves: put the name of the space the piece is on \nfirst and the space you want to move to second.  Examples: d8-d6 or h7-h5\nMake sure everything is lowercase and you seperate the spaces with dashes\n\n\n" << endl;
  while(running){
    //white's turn
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
        cout << "The move you have selected in not valid, please input a different move." << endl;
      }
    }

    char sf1 = space1.front();
    char sb1 = space1.back();
    char sf2 = space2.front();
    char sb2 = space2.back();

    switch(sf1){
      case 'a': current[2] = 1; break;
      case 'b': current[2] = 2; break;
      case 'c': current[2] = 3; break;
      case 'd': current[2] = 4; break;
      case 'e': current[2] = 5; break;
      case 'f': current[2] = 6; break;
      case 'h': current[2] = 7; break;
    }

    switch(sb1){
      case '1': current[1] = 1; break;
      case '2': current[1] = 2; break;
      case '3': current[1] = 3; break;
      case '4': current[1] = 4; break;
      case '5': current[1] = 5; break;
      case '6': current[1] = 6; break;
      case '7': current[1] = 7; break;
    }

    switch(sf2){
      case 'a': next[2] = 1; break;
      case 'b': next[2] = 2; break;
      case 'c': next[2] = 3; break;
      case 'd': next[2] = 4; break;
      case 'e': next[2] = 5; break;
      case 'f': next[2] = 6; break;
      case 'h': next[2] = 7; break;
    }

    switch(sb2){
      case '1': next[1] = 1; break;
      case '2': next[1] = 2; break;
      case '3': next[1] = 3; break;
      case '4': next[1] = 4; break;
      case '5': next[1] = 5; break;
      case '6': next[1] = 6; break;
      case '7': next[1] = 7; break;
    }

    cout << "This is the first square: " << current[1] << ","<< current[2] << endl;
    cout << "This is the second square: " << next[1] << ","<< next[2] << endl;

    //Black's turn
    valid = false;
    while(!valid){
      valid = true;
      cout << "Black, please select a move" << endl;
      cin >> move;
      cout << move << endl;
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

//    cout << "This is the first square: " << current[1] << ","<< current[2] << endl;
//    cout << "This is the second square: " << next[1] << ","<< next[2] << endl;
  }
}
