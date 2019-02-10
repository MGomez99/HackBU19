# HackBU19
*** move glut32.dll file to Windowss\SysWOW64 on 64 bit machines if you have difficulties running it ***
## Inspiration
Being four sophomore chess enthusiasts learning c++ and wanting to challenge ourselves, we decided on trying to make a game we could play with each other with the least amount of bugs.
If possible, we had/have plans to further the project (debugging) and implement a chess AI that uses a minimax algorithm and tree pruning to give a player's most optimal move given a board state.
## What it does
Takes user input through the terminal to move chess pieces and play a 2 player chess game
## How we built it
We used.  C++, OpenGL, Glut, and no other libraries to implement the code for the game. It was built 100% from scratch, including the graphics, and sprites. The algorithms utilized for play and movement were derived on the spot.  Requires glut and OpenGL to run.
## Challenges we ran into
Most of the errors come in from edge cases that were practically untraceable until you randomly stumbled upon it. Thus, the algorithms were the source problem, particularly checkmate cases and some possible moves. Given more time to polish the algorithms and debug, the game would be able to prevent incorrect play and force a standard chess game. 
## Accomplishments that we're proud of
Getting the GUI to work from scratch, creating the sprites using a paint tool, using OpenGL, and working with a relatively unfamiliar programming language.
## What we learned
We learned an immense amount about programming in C++. In addition, we learned to implement graphics using OpenGL and how to troubleshoot at 6 am. 
## What's next for Budget Chess
Refining all edge cases and confirming validity of every move are the most important issues to tackle. Our graphics are consistent, but we would also like to see what we can do in that area. The next "big thing" to tackle is implementing an AI
