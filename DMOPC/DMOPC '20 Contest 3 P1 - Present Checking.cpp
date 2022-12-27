#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	set<int> check;
	string output = " ";
	int n, input;
	cin >> n;
	while(n--) {
		cin >> input;
		if(!check.count(input)) {
			check.insert(input);
		} else {
			output = "NO";
		}
	}
	if(output==" ") {
		cout << "YES\n";
		return 0;
	} 
	cout << output << endl;
}
