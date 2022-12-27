#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string score[n];
	int wa = 0;
	for(int i=0; i<n; i++) {
		cin >> score[i];
		if(score[i]=="WA") {
			wa++;
		} 
	}
	int removeWA = 0.3 * wa;
	int currIR = 0;
	for(int i=0; i<n; i++) {
		if(score[i]=="WA" && removeWA>0) {
			score[i] = "AC";
			removeWA--;
		} else if(score[i]=="TLE") {
			score[i] = "WA";
		} else if(score[i]=="IR" && currIR<10) {
			currIR++;
			score[i] = "AC";
		} else if(score[i]=="IR" && currIR>=10 && currIR<20) {
			currIR++;
			score[i] = "WA";
		}
		cout << score[i] << "\n";
	}
}
