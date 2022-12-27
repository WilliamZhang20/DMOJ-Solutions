#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int a, b;
	cin >> a >> b;
	ll sum[b+1];
	memset(sum, 0, sizeof(sum));
	for(int i=1; i<b; i++) {
		int v = ceil(a/i)*i;
		if(i==v || v<a) {
			v+=i;
			if(i==v) {
				v+=i;
			}
		}
		//cout << i << ", " << v << '\n';
		for(; v<=b; v+=i) 			{
			//cout << i << ", v at " << v << endl;
			sum[v] += i;
		}
	}
	ll res = 0;
	for(int i=a; i<=b; i++) {
		//cout << "For " << i << ", sum " << sum[i] << "\n";
		res += abs(-sum[i]+i);
	}
	cout << res << endl;
}
