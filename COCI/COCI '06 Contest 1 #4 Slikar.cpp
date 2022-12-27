#include <bits/stdc++.h>
#define INF 999999
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int row, col;
	int r, c;
	int startX=0, startY=0;
	int destX=0, destY=0;
	queue<pair<int, int>> trk;
	cin >> row >> col;
	char **forest; // original grid
	int **grid; // tracking time
	int **flood; // tracking flood times
	forest = new char*[row];
	grid = new int*[row];
	flood = new int*[row];
	for(int i=0; i<row; i++) {
		forest[i] = new char[col];
		grid[i] = new int[col];
		flood[i] = new int[col];
		for(int j=0; j<col; j++) {
			cin >> forest[i][j];
			grid[i][j] = -1;
			flood[i][j] = INF;
			if(forest[i][j]=='*') {
				trk.push({i, j});
				flood[i][j] = 0;
			} else if(forest[i][j]=='S') {
				startX = i;
				startY = j;
				grid[i][j] = 0;
			} else if(forest[i][j]=='D') {
				destX = i;
				destY = j;
				flood[i][j] = INT_MAX;
			}
		}
	}
	pair<int, int> temp;
	// BFS Search to get flood times for each square
	while(!trk.empty()) {
		temp = trk.front();
		trk.pop();
		r = temp.first;
		c = temp.second;
		if(r>0 && forest[r-1][c]!='X' && forest[r-1][c]!='D' && flood[r-1][c]==INF) {
			flood[r-1][c] = flood[r][c]+1;
			trk.push({r-1, c});
		}
		if(r<row-1 && forest[r+1][c]!='X' && forest[r+1][c]!='D' && flood[r+1][c]==INF) {
			flood[r+1][c] = flood[r][c]+1;
			trk.push({r+1, c});
		}
		if(c>0 && forest[r][c-1]!='X' && forest[r][c-1]!='D' && flood[r][c-1]==INF) {
			flood[r][c-1] = flood[r][c] + 1;
			trk.push({r, c-1});
		}
		if(c<col-1 && forest[r][c+1]!='X' && forest[r][c+1]!='D' && flood[r][c+1]==INF) {
			flood[r][c+1] = flood[r][c] + 1;
			trk.push({r, c+1});
		}
	}
	// BFS Search for traversal
	grid[startX][startY] = 0;
	trk.push({startX, startY});
	while(!trk.empty()) {
		temp = trk.front();
		trk.pop();
		r = temp.first;
		c = temp.second;
		if(r>0 && forest[r-1][c]!='X' && grid[r-1][c]==-1 && flood[r-1][c]>grid[r][c]+1) {
			grid[r-1][c] = grid[r][c]+1;
      trk.push({r-1, c});
		}
    if(r<row-1 && forest[r+1][c]!='X' && grid[r+1][c]==-1 && flood[r+1][c]>grid[r][c]+1) {
			grid[r+1][c] = grid[r][c]+1;
      trk.push({r+1, c});
		}
    if(c>0 && forest[r][c-1]!='X' && grid[r][c-1]==-1 && flood[r][c-1]>grid[r][c]+1) {
			grid[r][c-1] = grid[r][c]+1;
      trk.push({r, c-1});
		}
    if(c<col-1 && forest[r][c+1]!='X' && grid[r][c+1]==-1 && flood[r][c+1]>grid[r][c]+1) {
			grid[r][c+1] = grid[r][c]+1;
      trk.push({r, c+1});
		}
		/*for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				cout << grid[i][j] << " ";
			} cout << endl;
		} cout << endl;*/
	}
	if(grid[destX][destY]!=-1) {
		cout << grid[destX][destY] << endl;
	} else {
		cout << "KAKTUS\n";
	}
}
