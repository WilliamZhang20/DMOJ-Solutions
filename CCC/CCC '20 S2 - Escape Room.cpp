#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, n;
	cin >> m >> n;
	vector<int> adj[MAXN];
	for(int i=1; i<=m; i++) {
		for(int j = 1; j<=n; j++) {
			int val;
			cin >> val;
			adj[i*j].push_back(val);
		}
	}
	bool visited[MAXN];
	queue<int> qu;
	visited[1] = true;
	qu.push(1); // first cell is (1, 1) => 1
	while(!qu.empty()) {
		int curr = qu.front();
		qu.pop();
		for(auto v: adj[curr]) {
			if(!visited[v]) {
				visited[v] = true;
				qu.push(v);
			}
		}
	}
	cout << (visited[m*n] ? "yes" : "no") << "\n";
}
