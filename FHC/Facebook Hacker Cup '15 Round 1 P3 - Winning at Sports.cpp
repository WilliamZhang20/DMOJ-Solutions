#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 2001;

ll dp1[MAXN][MAXN]; // stress-free
ll dp2[MAXN][MAXN]; // stressful
int s1, s2;

int stress_free(int n, int m) {
	if(n==s1 && m==s2) {
		return 1;
	} 
	if(n<=m) {
		return 0;
	} 
	if(n>s1 || m>s2) {
		return 0;
	}
	if(dp1[n][m] != -1) {
		return dp1[n][m];
	}
	int ans = (stress_free(n+1, m) + stress_free(n, m+1)) % MOD; 
	return dp1[n][m] = ans;
}

int stressfull(int n, int m) {
	if(m==s2) {
		return 1;
	} 
	if(n>m) {
		return 0;
	}
	if(n>s1 || m>s2) {
		return 0;
	}
	if(dp2[n][m] != -1) {
		return dp2[n][m];
	}
	int ans = (stressfull(n+1, m) + stressfull(n, m+1)) % MOD;
	return dp2[n][m] = ans;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	
	int test_case = 1;
	while(test_case<=t) {
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		char dash;
		cin >> s1 >> dash >> s2;
		cout << "Case #" << test_case << ": " << stress_free(1, 0) << " " << stressfull(0, 0) << "\n";
		test_case++;
	}
}
