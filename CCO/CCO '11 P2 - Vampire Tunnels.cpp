#include <bits/stdc++.h>

using namespace std;

struct edge {
	int destination;
	int weight;
	int light; // light exposure
};

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int s, n, e;
	cin >> s; // max time of sunlight
	cin >> n >> e;
	vector<vector<edge>> adj(n+5);
	for(int i=0; i<e; i++) {
		int ai, bi, wi, hi;
		cin >> ai >> bi >> wi >> hi;
		edge e1 = {bi, wi, hi*wi};
		edge e2 = {ai, wi, hi*wi};
		adj[ai].push_back(e1);
		adj[bi].push_back(e2);
	}
	vector<vector<int>> dist(n+5, vector<int>(s+5));
	for(int i=0; i<n; i++) {
		for(int j=0; j<=s; j++) {
			dist[i][j] = 2e9;
		}
	}
	queue<pair<int, int>> pq;
	pq.push({0, 0});
	dist[0][0] = 0;
	while(!pq.empty()) {
		pair<int, int> p = pq.front();
		pq.pop();
		for(edge u: adj[p.first]) {
		    int v = dist[p.first][p.second] + u.weight;
			if(p.second + u.light <= s && v < dist[u.destination][p.second + u.light]) {
			    dist[u.destination][p.second + u.light] = v;
			    pq.push({u.destination, p.second + u.light});
			}
		}
	}
	int ans = 2e9;
	for(int i=0; i<=s; i++) {
		ans = min(ans, dist[n-1][i]);
	}
	if(ans==2e9) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}
