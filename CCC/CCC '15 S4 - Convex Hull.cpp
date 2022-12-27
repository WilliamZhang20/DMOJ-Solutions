#include <bits/stdc++.h>

using namespace std;

struct edge {
	int destination;
	int time;
	int hull; // hull wearing out
};

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	vector<vector<edge>> adj(n+1);
	for(int i=0; i<m; i++) {
		int ai, bi, ti, hi;
		cin >> ai >> bi >> ti >> hi;
		edge e1 = {bi-1, ti, hi};
		edge e2 = {ai-1, ti, hi};
		adj[ai-1].push_back(e1);
		adj[bi-1].push_back(e2);
	}
	int a, b;
	cin >> a >> b;
	vector<vector<int>> dist(n+1, vector<int>(k+1));
	for(int i=0; i<n; i++) {
		for(int j=0; j<k; j++) {
			dist[i][j] = INT_MAX;
		}
	}
	queue<pair<int, int>> pq;
	pq.push({a-1, 0});
	dist[a-1][0] = 0;
	while(!pq.empty()) {
		pair<int, int> p = pq.front();
		pq.pop();
		for(edge u: adj[p.first]) {
		    int v = dist[p.first][p.second] + u.time;
			if(p.second + u.hull < k && v < dist[u.destination][p.second + u.hull]) {
			    dist[u.destination][p.second + u.hull] = v;
			    pq.push({u.destination, p.second + u.hull});
			}
		}
	}
	int ans = INT_MAX;
	for(int i=0; i<k; i++) {
		ans = min(ans, dist[b-1][i]);
	}
	if(ans==INT_MAX) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}
