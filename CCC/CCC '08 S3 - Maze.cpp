#include <bits/stdc++.h>
using namespace std;
// Maze problem - using BFS

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	queue<pair<int, int>> q;
  	pair<int, int> temp;
	char **maze;
	int **grid;
	int row, col;
	int t;
	cin >> t;
	while(t--) {
		cin >> row;
		cin >> col;
		maze = new char*[row];
		grid = new int*[row];
		for(int i=0; i<row; i++) {
			maze[i] = new char[col];
			grid[i] = new int[col];
			for(int j=0; j<col; j++) {
				cin >> maze[i][j];
			}
		}
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				grid[i][j] = -1;
			}
		}
		// Start BFS Traversal
		grid[0][0] = 1;
		q.push({0, 0});
		while(!q.empty()) {
			temp = q.front();
			q.pop();
			int r = temp.first;
			int c = temp.second;
			if((maze[r][c]=='+' || maze[r][c]=='|') && r>0 && maze[r-1][c]!='*' && grid[r-1][c]==-1) {
				grid[r-1][c]=grid[r][c]+1;
				q.push({r-1, c});
			}
			if((maze[r][c]=='+' || maze[r][c]=='|') && r<row-1 && maze[r+1][c]!='*' && grid[r+1][c]==-1) {
				grid[r+1][c]=grid[r][c]+1;
				q.push({r+1, c});
			}
			if((maze[r][c]=='+' || maze[r][c]=='-') && c>0 && maze[r][c-1]!='*' && grid[r][c-1]==-1) {
				grid[r][c-1]=grid[r][c]+1;
				q.push({r, c-1});
			}
			if((maze[r][c]=='+' || maze[r][c]=='-') && c<col-1 && maze[r][c+1]!='*' && grid[r][c+1]==-1) {
				grid[r][c+1]=grid[r][c]+1;
				q.push({r, c+1});
			}
		}
		cout << grid[row-1][col-1] << endl;
	}
}
