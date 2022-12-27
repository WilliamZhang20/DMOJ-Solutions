#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX_N = 18, MIN_VALUE = -1e6;
vector<pair<int, int>> graph[MAX_N]; // adj list
int dp[1 << MAX_N][MAX_N];
bool solved[1<<MAX_N][MAX_N];

int dp_value(int mask, int place) {
	if(place==n-1) {
		return 0;
	}
	if(solved[mask][place]) {
		return dp[mask][place];
	}
	for(int i=0; i<graph[place].size(); i++) {
		int next = graph[place][i].first;
		if(mask & (1<<next)) {
			dp[mask][place] = max(dp[mask][place], graph[place][i].second + dp_value(mask & ~(1 << next), next));
		}
	}
	solved[mask][place] = true;
	return dp[mask][place];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int s, d, l;
		cin >> s >> d >> l;
		graph[s].push_back({d, l});
	}
	memset(dp, MIN_VALUE, sizeof(dp));
	cout << dp_value(((1<<n)-1) & ~(1), 0) << '\n';
	return 0;
}
