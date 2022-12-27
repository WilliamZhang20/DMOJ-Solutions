#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	map<int, int> jump;
	jump[54] = 19;
	jump[9] = 34;
	jump[40] = 64;
	jump[90] = 48;
	jump[67] = 86;
	jump[99] = 77;
	int curr = 1;
	int step;
	cin >> step;
	while(step!=0 && curr<100) {
		if(curr+step<=100) {
			curr+=step;
		}
		if(jump.count(curr)) {
			curr = jump[curr];
		} 
		cout << "You are now on square " << curr << endl;
		cin >> step;
	}
	if(step==0) {
		cout << "You Quit!\n";
	} else {
		cout << "You Win!\n";
	}
}
