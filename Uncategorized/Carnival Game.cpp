#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	string board[n];
	int bucket[n];
	int dp[MAXN][MAXN];
	bool bt[MAXN][MAXN];
	memset(dp, INT_MAX, sizeof(dp));
	
	for(int i=0; i<n-1; i++) {
		cin >> board[i];
	}
	for(int i=0; i<n; i++) {
		cin >> bucket[i];
	}

	dp[0][0] = 0;
	for(int i=1; i<n; i++) {
		for(int j=0; j<=i; j++) {
			int left=0, right=0;
			if(j>=1 && board[i-1][j-1]=='L') {
				left = 1;
			} else if(j>=1 && board[i-1][j-1]=='R') {
				left = 0;
			}
			if(board[i-1][j]=='L') {
				right = 0;
			} else if(board[i-1][j]=='R') {
				right = 1;
			}
			if(j>=1 && j<i) {
				dp[i][j] = min(dp[i-1][j-1] + left, dp[i-1][j] + right);
				if(dp[i][j] == dp[i-1][j] + right) {
					bt[i][j] = true;
				}
			} else if(j>=1 && j==i) {
				dp[i][j] = dp[i-1][j-1] + left;
				
			} else {
				dp[i][j] = dp[i-1][j] + right;
				bt[i][j] = true;
			}
		}
	}
	int p = INT_MIN;
	int idx = 0;
	for(int i=0; i<n; i++) {
		int temp = p;
		p = max(p, bucket[i]-dp[n-1][i]);
		if(p>temp) {
			idx = i;
		}
	}
	cout << p << "\n";
	vector<pair<int, int>> flips;
	for(int i=n-1; i>0; i--) {
		if(bt[i][idx] && board[i-1][idx]=='R') {
			flips.push_back({i, idx+1});
		} else if(idx>0 && !bt[i][idx] && board[i-1][idx-1]=='L') {
			flips.push_back({i, idx});
		}
		if(!bt[i][idx]) {
			idx--;
		}
	}
	cout << flips.size() << "\n";
	for(int i=0; i<int(flips.size()); i++) {
		cout << flips[i].first << " " << flips[i].second << "\n";
	}
}
