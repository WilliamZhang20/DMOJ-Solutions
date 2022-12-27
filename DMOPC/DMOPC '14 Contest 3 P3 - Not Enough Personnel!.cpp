#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	int n;
	cin >> n;
	pair<int, string> arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	int q;
	cin >> q;
	for(int i=0; i<q; i++) {
		int s, d;
		cin >> s >> d;
		int high = s + d;
		int val = INT_MAX;
		string vet = "*";
		for(int j=0; j<n; j++) {
			if(arr[j].first<=s+d && arr[j].first>=s && arr[j].first<val) 			{
				val = arr[j].first;
				vet = arr[j].second;
			}
		}
		if(vet!="*") {
			cout << vet << "\n";
		} else {
			cout << "No suitable teacher!\n";
		}
	}
}
