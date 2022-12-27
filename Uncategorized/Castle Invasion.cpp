#include <bits/stdc++.h>
#define int long long
#define MAX_VAL 1000000
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int maxC = 0, maxR = 0;
	int row[n], row_freq[MAX_VAL+1] = {0};
	int col[n], col_freq[MAX_VAL+1] = {0};
	for(int i=0; i<n; i++) {
		cin >> col[i];
		maxC = max(maxC, col[i]);
		col_freq[col[i]]++;
	}
	for(int i=0; i<n; i++) {
		cin >> row[i];
		maxR = max(maxR, row[i]);
		row_freq[row[i]]++;
	}
	if(maxC != maxR) {
		cout << "-1\n";
		return 0;
	}
	int ans = 0;
	int pfreq_r[MAX_VAL+1] = {0}, pfreq_c[MAX_VAL+1] = {0};
	for(int i=1; i<=maxR; i++) {
		pfreq_r[i] = pfreq_r[i-1] + row_freq[i];
	}
	for(int i=1; i<=maxC; i++) {
		pfreq_c[i] = pfreq_c[i-1] + col_freq[i];
	}
	for (int i=0; i<n; i++) {
		ans += (n-pfreq_r[col[i]-1]) * col[i];
		ans += (n-pfreq_c[row[i]]) * row[i];
	}
	cout << ans << endl;
	return 0;
}
