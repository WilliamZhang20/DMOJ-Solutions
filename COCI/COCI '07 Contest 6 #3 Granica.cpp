#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	int m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	m = abs(a[0]-a[1]);
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			m = __gcd(m, abs(a[i]-a[j]));
		}
	}
	for(int i=2; i*i<=m; i++) {
		if(m%i==0) {
			if(m/i==i) {
				cout << i << " ";
			} else {
				cout << i << " " << m/i << " ";
			}
		}
	}
	cout << m << "\n";
}
