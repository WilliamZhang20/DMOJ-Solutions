#include <bits/stdc++.h>
using namespace std;

int n, m, t;
const int MAXN = 1e3+1;
vector<int> adj[MAXN];
int dist_grid[MAXN][MAXN] = {0};

void bfs(int node) {
	queue<int> q;
	q.push(node);
	bool visited[MAXN] = {false};
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(auto edge: adj[curr]) {
			if(!visited[edge]) {
				dist_grid[node][edge] = dist_grid[node][curr] + t;
				q.push(edge);
				visited[edge] = true;
			}
		}
	}
}

int main() {
    cin >> n >> m >> t;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
	for(int i=1; i<=n; i++) {
		bfs(i);
	}
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
		int res = dist_grid[a][b];
		if(res == 0) {
			cout << "Not enough hallways!\n";
		} else {
			cout << res << '\n';
		}
    }
}
