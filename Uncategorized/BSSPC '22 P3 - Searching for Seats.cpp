#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define sz(x) (int)x.size()
using namespace std;

const int MAX = 1e3+1;
int n, m, k;
bool seats[MAX][MAX];

bool solve(int i, int j) {
	int count = 0; // count friends
	if(i>1) {
		if(seats[i-1][j])
			count++;
		if(j>1 && seats[i-1][j-1]) 
			count++;
	} 
	if(i<n) {
		if(seats[i+1][j])
			count++;
		if(j<m && seats[i+1][j+1])
			count++;
	}
	if(j>1) {
		if(seats[i][j-1])
			count++;
		if(i<n && seats[i+1][j-1])
			count++;
	}
	if(j<m) {
		if(seats[i][j+1])
			count++;
		if(i>1 && seats[i-1][j+1])
			count++;
	}
	if(count>=3) {
		return true;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	scan(n);
	scan(m);
	scan(k);
	for(int i=0; i<k; i++) {
		int r_i, c_i;
		scan(r_i);
		scan(c_i);
		seats[r_i][c_i] = true;
	}
	int ans = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!seats[i][j]) {
				if(solve(i, j)) {
					ans++;
				}
			}
		}
	}
	cout << ans << "\n"; 
}
