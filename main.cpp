<<<<<<< HEAD
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
  if(space1.length() != 2  || space2.length()){
    cout << "invalid input" << endl;
  }
  if(space1.front() == 'a'){
    cout << "works" << endl;
  }

//  while(running){
//  }
}
=======
#include <cstdlib>
#include <iostream>
#include "game.h"

using namespace std;

int main(){
  bool running = true;
//  String move;
  cout << "\n\n\nQuick explanation of how to input moves: put the first letter of the name of the piece\n(king = k, queen = q, rook = r, bishop = b, knight = k and no letter for pawn) and then \nput the name of the space the piece is on first and the space you want to move to second.\nexamples: qd8d6 or h7h5.  Make sure everything is lowercase!\n\n\n" << endl;
//  while(running){
//    cout << "White, please select a move" << endl;
//    cin >> move;
//  }
}
>>>>>>> 8c0a7724f5756de62c202c71295ce4def2b44563
