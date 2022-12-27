#include <bits/stdc++.h>

using namespace std;

const int MT = 1e4+1;

vector<int> dp1(MT); // previous row

int main() {
 	cin.sync_with_stdio(0);
    cin.tie(0);
	int n, t;
	cin >> n >> t;
	while(n--) {
		vector<int> dp2(MT); // current row;
		int times[3], values[3];
		for(int i=0; i<3; i++) {
			cin >> times[i] >> values[i];
		}
		for(int i=0; i<=t; i++) {
			dp2[i] = dp1[i];
			for(int j=0; j<3; j++) {
                if(i>=times[j]) {
                    dp2[i] = max(dp2[i], dp1[i-times[j]] + values[j]);
                }
            }
		}
		dp1 = dp2;
	}
	cout << *max_element(begin(dp1), end(dp1)) << "\n";
}
