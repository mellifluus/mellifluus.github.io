#include <iostream>
using namespace std;

#define mazeSize 8

bool solveMaze(int maze[mazeSize][mazeSize], int x, int y,int solutionMatrix[mazeSize][mazeSize]);

void printSolution(int solutionMatrix[mazeSize][mazeSize]) {
  for (int i = 0; i < mazeSize; i++) {
    for (int j = 0; j < mazeSize; j++) {
      cout << solutionMatrix[i][j] << "  ";
    }
    cout << endl;
  }
}

bool isSafe(int maze[mazeSize][mazeSize], int x, int y) {
  return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 1;
}

bool startMaze(int maze[mazeSize][mazeSize]) {
  int solutionMatrix[mazeSize][mazeSize] = { 
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  if (solveMaze(maze, 0, 0, solutionMatrix) == false) {
    cout << "Solution doesn't exist" << endl;
    return false;
  }

  printSolution(solutionMatrix);
  return true;
}

bool solveMaze(int maze[mazeSize][mazeSize], int x, int y, int solutionMatrix[mazeSize][mazeSize])
{
  cout << "in solveMaze" << endl;
  // GOAL
  if (x == mazeSize - 1 && y == mazeSize - 1 && maze[x][y] == 1) {
    solutionMatrix[x][y] = 1;
    return true;
  }

  if (isSafe(maze, x, y) == true) {

    if (solutionMatrix[x][y] == 1) {
      return false;
    }

    solutionMatrix[x][y] = 1;
    // // MOVE UP
    // if (solveMaze(maze, x - 1, y, solutionMatrix) == true) {
    //   return true;
    // }
    // MOVE DOWN
    if (solveMaze(maze, x + 1, y, solutionMatrix) == true) {
      return true;
    }
    // // MOVE LEFT
    // if (solveMaze(maze, x, y - 1, solutionMatrix) == true) {
    //   return true;
    // }
    // MOVE RIGHT
    if (solveMaze(maze, x, y + 1, solutionMatrix) == true) {
      return true;
    }
    // BACKTRACK
    solutionMatrix[x][y] = 0;
    return false;
  }
  return false;
}

int main()
{
  int maze[mazeSize][mazeSize] = { 
    { 1, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 1, 0, 0, 0 },
    { 1, 0, 1, 0, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 1 },
  };
  startMaze(maze);

  return 0;
}