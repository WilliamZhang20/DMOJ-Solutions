#include <bits/stdc++.h>
using namespace std;

int r, c;
char grid[110][110];

void search(int i, int j) {
	if(grid[i][j]=='X' || grid[i][j]=='C' || i<0 || i==r || j<0 || j==c) {
		return;
	}
	grid[i][j] = 'C';
	search(i-1, j);
	search(i+1, j);
	search(i, j-1);
	search(i, j+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> grid[i][j];
		}
	}
	int rooms = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(grid[i][j] == '.') {
				search(i, j);
				rooms++;
			}
		}
	}
	cout << rooms << '\n';
}
