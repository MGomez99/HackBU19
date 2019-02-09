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
  cout << "\n\n\nQuick explanation of how to input moves: put the name of the space the piece is on first and the space you want to move to second.\nexamples: d8-d6 or h7-h5\nMake sure everything is lowercase and you seperate the spaces with dashes\n\n\n" << endl;
  cout << "White, please select a move" << endl;
  cin >> move;
  space1 = move.substr(0, move.find(delim));
  space2 = move.substr(move.find(delim)+1, move.length());
  cout << space1 << endl;
  cout << space2 << endl;
  if(space1.length() != 2  || space2.length() != 2){
    cout << "invalid input" << endl;
  }
  if(space1.front() < 97 ||  space1.front() > 104){
    cout << "invalid first char 1" << endl;
  }
  if(space2.front() < 97 ||  space2.front() > 104){
    cout << "invalid first char 2" << endl;
  }
  if(space1.back() < 49 || space1.back() > 56){
    cout << "invalid num 1" << endl;
  }
  if(space2.back() < 49 || space2.back() > 56){
    cout << "invalid num 2" << endl;
  }

//  while(running){
//  }
}
