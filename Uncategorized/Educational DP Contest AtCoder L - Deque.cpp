#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[3001][3001] {0};

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	int seq[3000];
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> seq[i];
	}	
	for(int l=n; l>=1; l--) {
		for(int r=l; r<=n; r++) {
			if(l==r) {
				dp[l][r] = seq[l];
			} else {
				dp[l][r] = max(seq[l]-dp[l+1][r], seq[r]-dp[l][r-1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}
