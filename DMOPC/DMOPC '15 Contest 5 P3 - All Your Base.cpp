#include <bits/stdc++.h>
using namespace std;

int anyBaseToDecimal(string num, int numBase) {
    int deci=0;
    reverse(num.begin(), num.end());
    for(int i=0; i<num.size(); i++) {
        deci += (num[i]-'0')*pow(numBase, i);
    }
    return deci;
} 

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int e;
	int n;
	cin >> e >> n;
	int a[n+1];
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=n-1; i>=1; i--) {
		a[i] = anyBaseToDecimal(to_string(a[i]), a[i+1]);
	}
	cout << anyBaseToDecimal(to_string(e), a[1]) << endl;
}
