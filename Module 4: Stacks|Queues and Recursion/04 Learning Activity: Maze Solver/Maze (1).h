#ifndef MAZE_H
#define MAZE_H

#include <iostream>

class Maze{

public:

    void solve(){
        if(solve(startRow, startCol)){
            std:: cout << "IT WORKED\n";
        }
        else {
            std::cout << "No soultion";
        }
    }

//Recursive method to solve the maze
    bool solve(int currR, int currC){
        if(currR == endRow && currC == endCol){
            return true;
        }
        if(!isEmpty(currR, currC)){
            return false;
        }
        maze[currR][currC] = '+';
        if(solve((currR+1), currC) || solve((currR-1), currC) || solve(currR, (currC+1)) || solve(currR, (currC-1))) {
            return true;
        }
        else{
            maze[currR][currC] = S;
            return false;
        }
        return false;

    }

// print the current state of the maze
    void printMaze()
    {
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                std::cout << maze[i][j];
            }
            std::cout << std::endl;

        }
    }

//Determines if a location in the maze is empty
    bool isEmpty(int r, int c){
        if(r >= 0 && c >= 0 && c < WIDTH && r < HEIGHT){
            if(maze[r][c] == S) {
                return true;
            }
        }
        return false;
    }

private:
    int startRow = 2;
    int startCol = 0;
    int endRow = 4;
    int endCol = 12;

    const char W = '#';
    const char S = ' ';
    static const int WIDTH = 13;
    static const int HEIGHT = 14;
    //Maze:  char(219) is a wall, space is empty, . is the path

    char maze[ HEIGHT ][ WIDTH ] =
            { {W, W, W, W, W, W, W, W, W, W, W, W},
              {  W, S, S, S, W, S, S, S, S, S, S, W},
              {  S, S, W, S, W, S, W, W, W, W, S, W},
              {  W, W, W, S, W, S, S, S, S, W, S, W},
              {  W, S, S, S, S, W, W, W, S, W, S, S},
              {  W, W, W, W, S, W, S, W, S, W, S, W},
              {  W, S, S, W, S, W, S, W, S, W, S, W},
              {  W, W, S, W, S, W, S, W, S, W, S, W},
              {  W, S, S, S, S, S, S, S, S, W, S, W},
              {  W, W, W, W, W, W, S, W, W, W, S, W},
              {  W, S, S, S, S, S, S, W, S, S, S, W},
              {  W, W, W, W, W, W, W, W, W, W, W, W} };
};
#endif // MAZE_H