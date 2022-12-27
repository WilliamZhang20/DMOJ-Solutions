#include <bits/stdc++.h>

using namespace std;

int board[9][9];

void knightMove(int x, int y, int steps) {
  // modify board recursively
  if(x>0 && x<=8 && y>0 && y<=8 && steps<board[x][y]) {
    board[x][y] = steps;
    // move it everywhere it can go
    knightMove(x-1, y-2, steps+1);
    knightMove(x-2, y-1, steps+1);
    knightMove(x+1, y+2, steps+1);
    knightMove(x+2, y+1, steps+1);
    knightMove(x+2, y-1, steps+1);
    knightMove(x+1, y-2, steps+1);
    knightMove(x-1, y+2, steps+1);
    knightMove(x-2, y+1, steps+1);
  } else {
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int xStart, yStart;
  int xEnd, yEnd;
  cin >> xStart >> yStart;
  cin >> xEnd >> yEnd;
  // init board
  for(int i=1; i<=8; i++) {
    for(int j=1; j<=8; j++) {
      board[i][j] = 99999; // initialize to INF
    }
  }
  knightMove(xStart, yStart, 0);
  cout << board[xEnd][yEnd] << endl; // get the answer
}
