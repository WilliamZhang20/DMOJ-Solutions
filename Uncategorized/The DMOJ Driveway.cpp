#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t=1, m;
	deque<string> driveway;
	string x, c; 
	cin >> t >> m;
	while(t--) {
		cin >> x >> c;
		if(c=="in") {
			driveway.push_back(x);
		} else {
			if(driveway.back()==x) {
				driveway.pop_back();
			} else if(driveway.front()==x) {
				driveway.pop_front();
				m--;
			}
		}
	}
	deque<string>::iterator it;
	for(it=driveway.begin(); it!=driveway.end(); it++) {
		cout << *it << endl;
	}
}
