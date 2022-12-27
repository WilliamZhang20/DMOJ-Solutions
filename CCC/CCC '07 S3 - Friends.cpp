#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int friends[10000] {0};
	bool visited[10000];
	int n;
	int x, y;
	int distance;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int person, assignment;
		cin >> person >> assignment;
		friends[person] = assignment;
	}
	cin >> x >> y;
	while(x!=0 && y!=0) {
		fill(begin(visited), begin(visited)+10000, false);
		distance = -1;
		while(!visited[x] && x!=y) {
			visited[x]=true;
			distance++;
			x = friends[x];
		}
		if(x==y) {
			cout << "Yes " << distance << endl;
		} else {
			cout << "No" << endl;
		}
		cin >> x >> y;
	}
}
