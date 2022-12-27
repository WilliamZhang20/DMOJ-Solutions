#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, d, k, x;
	cin >> n >> d >> k >> x;
	ll speed[n];
	for(int i=0; i<n; i++) {
		cin >> speed[i];
	}
	ll p;
	cin >> p;
	for(int i=0; i<n; i++) {
		while(speed[i]>=p && k>0) {
			speed[i] = speed[i] * (100-x)/100;
			k--;
		}
		if(speed[i]>=p) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
