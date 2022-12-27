#include <bits/stdc++.h>

const int MAXN = 20;
const double MINVAL = -1;

using namespace std;

int n;
double probs[MAXN][MAXN];
double dp[1<<MAXN];
bool solved[1<<MAXN];

double solve(int r, int mask) {
	if(mask == 0) {
		return 1.0;
	}
	if(solved[mask]) {
		return dp[mask];
	}
	for(int i=0; i<n; i++) {
		if(mask & (1<<i)) {
			dp[mask] = max(dp[mask], probs[r][i]/100.0 * solve(r-1, mask & ~(1<<i)));
		}
	}
	solved[mask] = true;
	return dp[mask];
}

// DP bitmasking
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> probs[i][j];
		}
	}
	fill_n(dp, MAXN, MINVAL);
	cout << setprecision(9) << fixed << solve(n-1, (1<<n)-1) * 100.0 << "\n"; // all bits on
}
