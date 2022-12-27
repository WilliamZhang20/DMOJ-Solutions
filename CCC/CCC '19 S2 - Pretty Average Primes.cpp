#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=2; i<=2*n; i++) {
			int a = i;
			int b = 2*n - i;
			if(isPrime(a) && isPrime(b) && 2*n==a+b) {
				cout << a << " " << b << endl;
				break;
			}
		}
	}
}
