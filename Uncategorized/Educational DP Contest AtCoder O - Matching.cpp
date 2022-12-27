#include <bits/stdc++.h>

const int MOD = 1e9+7;
const int MAX_N = 21;

using namespace std;

int n;
bool belong[21][21];
int dp[1<<MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> belong[i][j];
		}
	}
	dp[0] = 1;
	for(int mask = 1; mask<(1<<n); mask++) {
		int curr = n - __builtin_popcount(mask);
		for(int i = 0; i < n; i++) {
			if(belong[curr][i] && (mask & (1<<i))) {
				dp[mask] += dp[mask & ~(1<<i)];
				dp[mask] %= MOD;
			}
		}
	}
	cout << dp[(1<<n)-1] << '\n'; 
}
