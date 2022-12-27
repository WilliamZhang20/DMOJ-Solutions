#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ull a, b, c;
	ull mod = 42069900169420;
	cin >> a >> b >> c;
	cout << (a+b+c) % mod << "\n";
	return 0;
}
