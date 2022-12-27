#include <bits/stdc++.h>
using namespace std;

void print(double val) {
	cout << fixed << val << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	pair<double, double> tracks[n];
	for(int i=0; i<n; i++) {
		cin >> tracks[i].first >> tracks[i].second;
	}
	sort(tracks, tracks+n);
	double spd = -100000.0;
	for(int i=1; i<n; i++) {
		double temp = (tracks[i].second-tracks[i-1].second)/(tracks[i].first - tracks[i-1].first);
		//cout << tracks[i].first << " " << tracks[i].second << ' '<< temp<< '\n';
		if(abs(temp) > spd) {
			spd = abs(temp);
		}
	}
	print(spd);
}
