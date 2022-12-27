#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b, k, g; // Luka starts at A, k minutes AFTER George
	cin >> a >> b >> k >> g;
	int George[1001];
	int dist[1001];
	set<pair<int, int>> visited;
	pair<int, int> adj[1001][1001]; // adj matrix storing {Luka, George}
	for(int i=0; i<g; i++) {
		cin >> George[i];
	}
	for(int i=1; i<=n; i++) {
		dist[i] = INF;
		for(int j=1; j<=n; j++) {
			adj[i][j].first = INF;
		}
	}
	for(int i=0; i<m; i++) {
		int a1, b1, l1;
		cin >> a1 >> b1 >> l1;
		adj[a1][b1].first = l1;
		adj[b1][a1].first = l1;
	}
	int time = 0-k; // tracking George's time
	for(int i=1; i<g; i++) {
		adj[George[i]][George[i-1]].second = time;
		adj[George[i-1]][George[i]].second = time;
		visited.insert({George[i-1], George[i]});
		visited.insert({George[i], George[i-1]});
		time += adj[George[i-1]][George[i]].first;
	}
	dist[a] = 0;
	queue<int> qu;
	qu.push(a);
	while(!qu.empty()) {
		int curr = qu.front(); // current node
		qu.pop();
		for(int i=1; i<=n; i++) {
			if(adj[curr][i].first == INF) {
				continue;
			}
			int gt = adj[curr][i].second; // George's arrival
			int wt = adj[curr][i].first;
			if(visited.count({curr, i})==1 && gt < dist[curr] && gt + wt > dist[curr]) { // George arrives before Luka, difference between them is less than the road's length.
				wt += wt - (dist[curr] - gt); // increment weight by difference between weight and (current time subtracted by George's time)
			}
			if(dist[curr] + wt < dist[i]) {
				dist[i] = dist[curr] + wt;
				qu.push(i);
			}
		}
	}
	cout << dist[b] << "\n";
}
