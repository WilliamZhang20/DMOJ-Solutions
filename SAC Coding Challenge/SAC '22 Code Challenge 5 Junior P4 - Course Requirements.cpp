#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

const int MAXN = 2e5 + 1;
vi adj[MAXN];
int in[MAXN];
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for(int i=1, u, v; i<=n; i++) {
		cin >> u;
		for(int j=0; j<u; j++) {
			cin >> v;
			adj[v].pb(i);
			in[i]++;
		}
	}
	for(int i=1; i<=n; i++) {
		if(!in[i]) {
			q.push(i);
			cout << i << " ";
		}
	}
	vector<int> ans;
	while(!q.empty()) {
		//cout << "start ";
		int e = q.front(); q.pop();
		//cout << e << "\n";
		for(auto &v: adj[e]) {
			if(--in[v] == 0) {
				q.push(v);
				cout << v << " ";
			} else {
				//cout << "2: " << v << "\n";
			}
		}
	}
	cout << "\n";
}
