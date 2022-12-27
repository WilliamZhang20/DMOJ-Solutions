#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3+1;
double dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int n;
	cin >> n;
	dp[0][0] = 1.0;
	for(int i=1; i<=n; i++) {
		double p;
		cin >> p;
		dp[i][0] = 1.0;
		for(int j=1; j<i; j++) {
			dp[i][j] = (p*dp[i-1][j-1]) + ((1.0-p)*dp[i-1][j]);
		}
		dp[i][i] = p*dp[i-1][i-1];
	}
	cout << setprecision(10) << fixed << dp[n][int(ceil(double(n/2.0)))] << "\n";
}
