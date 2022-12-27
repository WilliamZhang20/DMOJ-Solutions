#include <bits/stdc++.h>
using namespace std;
// Stack data structure
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, p;
	int mov = 0;
	int string, fret;
	stack<int> frets[7];
	cin >> n >> p;
	while(n--) {
		cin >> string >> fret;
		if(frets[string].empty() || (!frets[string].empty() && frets[string].top()<fret)) {
			frets[string].push(fret);
			mov++;
		} else if(!frets[string].empty() && frets[string].top()>fret) {
			while(!frets[string].empty() && frets[string].top()>fret) {
				frets[string].pop();
				mov++;
			}
			if(!frets[string].empty() && frets[string].top()<fret) {
				frets[string].push(fret);
				mov++;
			} else if(frets[string].empty()) {
				frets[string].push(fret);
				mov++;
			}
		} 
	}
	cout << mov << endl;
}
