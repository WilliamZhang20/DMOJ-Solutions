#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int m;
		cin >> m;
		string str;
		cin.ignore();
		getline(cin, str);
		str.erase(m-1, 1);
		cout << i << " " << str << '\n';
	}
	return 0;
}
