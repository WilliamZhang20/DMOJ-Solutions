#include <bits/stdc++.h>

using namespace std;

signed main() {
	// Dijkstra's Algorithm
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> adj[n+1];
	while(t--) {
		int x, y, cxy;
		cin >> x >> y >> cxy;
		if(x>=1 && x<=n && y>=1 && y<=n) {
			adj[x].push_back({y, cxy});
			adj[y].push_back({x, cxy});
		}
	}
	int k;
	cin >> k;
	vector<int> city_costs(n+1, INT_MAX);
	while(k--) {
		int z, pz;
		cin >> z >> pz;
		city_costs[z] = pz;
	}
	int d;
	cin >> d;
	int dist[n+1];
	for(int i=1; i<=n; i++) {
		dist[i] = INT_MAX;
	}

	set<pair<int, int>> pq;
	pq.insert({0, d}); // making final node the source to find all distances
	dist[d] = 0;
	while(!pq.empty()) {
		int curr = pq.begin()->second;
		pq.erase(pq.begin());
		for(auto x: adj[curr]) {
			int v = x.first, w = x.second;
			if(dist[curr] + w < dist[v]) {
				dist[v] = dist[curr]+w;
				pq.insert({dist[v], v});
			}
		}
	}

	int cost = INT_MAX;
	for(int i=1; i<=n; i++) {
		if(city_costs[i]!=INT_MAX) {
			cost = min(cost, city_costs[i] + dist[i]);
		}
	}
	cout << cost << '\n';
}
