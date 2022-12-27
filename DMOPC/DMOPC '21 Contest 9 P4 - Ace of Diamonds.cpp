#include <bits/stdc++.h>
using namespace std;

void flip(char& coin) {
	if(coin=='X') {
		return;
	} else if(coin=='H') {
		coin = 'T';
	} else {
		coin = 'H';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int totalHeads = 0;
	char grid[n][m];
	char rep[n];
	for(int i=0; i<n; i++) {
		int rowHeads = 0;
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
			if(grid[i][j]=='H') {
				totalHeads++;
				rowHeads++;
			}
		}
		if(rowHeads%2==0) {
			rep[i] = 'T';
		} else {
			rep[i] = 'H';
		}
	}
	if(totalHeads%2==0) {
		cout << "-1\n";
		return 0;
	} 
	for(int i=0; i<n; i++) {
		if(rep[i]=='H') {
			for(int j=0; j<m; j++) {
				if(grid[i][j]=='H') {
					cout << i+1 << " " << j+1 << "\n";
					if(i>0) {
						flip(grid[i-1][j]);
					}
					if(j>0) {
						flip(grid[i][j-1]);
					}
					if(i<n-1) {
						flip(grid[i+1][j]);
					}
					if(j<m-1) {
						flip(grid[i][j+1]);
					}
					grid[i][j] = 'X';
					if(j<1) {
						j--;
					} else {
						j-=2;
					}
				}
			}
			if(i>0) {
				flip(rep[i-1]);
			}
			if(i<n-1) {
				flip(rep[i+1]);
			}
			rep[i] = 'X';
			if(i<1) {
				i--;
			} else {
				i-=2;
			}
		}
	}
}
