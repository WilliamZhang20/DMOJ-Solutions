#include <bits/stdc++.h>

using namespace std;

int dp[151][301][101];
bool dp_solved[151][301][101];

int dp_solve(int curr, int r, int time_left, int space_left, int val[], int time[], int units[]) {
	if(dp_solved[curr][time_left][space_left]==true) {
		return dp[curr][time_left][space_left];
	}
	if(curr>r || time_left==0 || space_left==0) {
		return 0;
	}
	int res = 0;
	if(time[curr-1]>time_left || units[curr-1]>space_left) {
		res = dp_solve(curr+1, r, time_left, space_left, val, time, units);
	} else {
		res = max(dp_solve(curr+1, r, time_left-time[curr-1], space_left-units[curr-1], val, time, units)+val[curr-1], dp_solve(curr+1, r, time_left, space_left, val, time, units));
	}
	dp_solved[curr][time_left][space_left] = true;
	dp[curr][time_left][space_left] = res;
	return res;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int m, u, r;
	cin >> m >> u >> r;
	int impress[r], time[r], unitsServed[r];
	for(int i=0; i<r; i++) {
		cin >> impress[i] >> time[i] >> unitsServed[i];
	}
	int n = 1;
	int time_left = m;
	int space_left = u;
	cout << dp_solve(n, r, time_left, space_left, impress, time, unitsServed) << "\n";
}
