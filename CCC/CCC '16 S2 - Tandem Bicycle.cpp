#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5 * 1e5;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int qu;
	int n;
	cin >> qu >> n;
	int dmoj[n], peg[n];
	for(int i=0; i<n; i++) {
		cin >> dmoj[i];
	}
	for(int i=0; i<n; i++) {
		cin >> peg[i];
	}
	sort(dmoj, dmoj+n);
	sort(peg, peg+n);
	if(qu==1) {
		int res = 0;
		for(int i=0; i<n; i++) {
			res += max(dmoj[i], peg[i]);
		}
		cout << res;
	} else {
		int res = 0;
		for(int i=0; i<n; i++) {
			int j = i+1;
			res += max(dmoj[n-j], peg[i]);
		}
		cout << res;
	}
	cout << '\n';
}
