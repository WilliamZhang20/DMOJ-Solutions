#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 2*1e6;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll q[MAXN];
	for(int i=0; i<n*2; i++) {
		cin >> q[i];
	}
	sort(q, q+(n*2));
	ll res = 0;
	for(int i=0; i<n*2; i+=2) {
		res += q[i+1] - q[i];
	}
	cout << res << '\n';
}
