#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	string t;
	cin >> s;
	cin >> t;
	for(int shift=0; shift<=25; shift++) {
		if(s.find(t)!=string::npos) {
			cout << shift << "\n";
			cout << s << "\n";
			return 0;
		} 
		for(int i=0; i<int(s.length()); i++) {
			s[i] = s[i] - 1;
			if(s[i]=='a'-1) {
				s[i] = 'z';
			}
		}
	}
}
