#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int count = 0;
	while(n!=1) {
		if(n%2==0) {
			n/=2;
		} else {
			n = 3*n+1;
		}
		count++;
	}
	cout << count << endl;
}
