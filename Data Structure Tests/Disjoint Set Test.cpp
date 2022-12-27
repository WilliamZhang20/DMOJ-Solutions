#include <bits/stdc++.h>
#define S second
#define F first
using namespace std;

class UnionFind {
	public:
		UnionFind(int n) {
			parent.assign(n+1, 0);
			rank.assign(n+1, 1);
			for(int i=1; i<=n; i++) parent[i] = i;
		}
		int find_set(int i) {
			while(parent[i]!=i) {
				i = parent[i];
			}
			return i;
		}
		void union_set(int a, int b) {
			if(rank[a]<rank[b]) {
			    swap(a, b);
			}
			parent[b] = a;
			rank[a] += rank[b];
		}
	private:
		vector<int> parent, rank;
};

vector<int> mst;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	for(int i=1; i<=m; i++) {
		int u_i, v_i;
		cin >> u_i >> v_i;
		int r1 = uf.find_set(u_i);
		int r2 = uf.find_set(v_i);
		if(r1!=r2) {
		    mst.push_back(i);
		    uf.union_set(r1, r2);
		}
	}
	if(int(mst.size())<n-1) {
		cout << "Disconnected Graph\n";
		return 0;
	}
	for(auto au: mst) {
		cout << au << '\n';
	}
	return 0;
}
