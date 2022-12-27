#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map<int, vector<pair<int, int>>> list;
	
	int n, v;
	cin >> n >> v;
	int coins[2001];
	int dp[10001];
	
	for(int i=1; i<=n; i++) {
		cin >> coins[i];
	}
	int maxRequest = INT_MIN;
	for(int i=1; i<=v; i++) { // targets
		int c, l;
		cin >> c >> l; // amount wanted, coins accepted
		list[l].push_back({c, i});
		maxRequest = max(maxRequest, c);
	}
	memset(dp, INT_MAX, sizeof(dp)); 
	dp[0] = 0;

	int res[100001];
	for(int coin=1; coin<=n; coin++) {
		int curr = coins[coin];
		for(int i=curr; i<=maxRequest; i++) { 
			int val = dp[i];
			if(val==-1) {
				val = INT_MAX;
			}
			if(dp[i-curr]!=-1)  {
				val = min(val, dp[i-curr]+1);
			}
			if(val==INT_MAX) {
				dp[i] = -1;
			} else {
				dp[i] = val;
			}
		}
		for(int i=0; i<int(list[coin].size()); i++) {
			res[list[coin][i].second] = dp[list[coin][i].first];
		}
	}

	for(int i=1; i<=v; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}
