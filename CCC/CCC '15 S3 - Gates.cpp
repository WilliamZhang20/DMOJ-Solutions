#include <bits/stdc++.h>
using namespace std;
// disjoint set union (DSU)

int parent[100001]; // parent set containing all roots

int find_set(int v) { // find representative value
	if(parent[v]!=v) {
		parent[v] = find_set(parent[v]);
	}
	return parent[v];
}

void union_sets(int a, int b) { // merge two sets
    a = find_set(a);
    b = find_set(b);
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int g; // number of gates
	int p; // number of planes
	int wantedGate;
	int gateRoot;
	cin >> g >> p;
	for(int i=0; i<100001; i++) {
		parent[i] = i;
	} 
	int t = 0;
	bool canGo = true;
	while(t<p && canGo) {
		cin >> wantedGate;
		gateRoot = find_set(wantedGate); // parent of set tree
		if(gateRoot==0) { // at this step, the values are 'unioned' and there are no more gates available
			cout << t << endl;
			canGo = false;
		}
		union_sets(gateRoot, gateRoot-1);
		t++;
	}
	if(canGo) {
		cout << p << endl;
	}
}
