#include <bits/stdc++.h>
using namespace std;

string revComplement(string str) {
	for(int i=0; i<str.length(); i++) {
		switch(str[i]) {
			case 'A': 
				str[i] = 'T';
				break;
			case 'T':
				str[i] = 'A';
				break;
			case 'C':
				str[i] = 'G';
				break;
			case 'G':
				str[i] = 'C';
				break;
		}
	}
	reverse(str.begin(), str.end());
	return str;
}

string complement(string str) {
	for(int i=0; i<str.length(); i++) {
		switch(str[i]) {
			case 'A': 
				str[i] = 'T';
				break;
			case 'T':
				str[i] = 'A';
				break;
			case 'C':
				str[i] = 'G';
				break;
			case 'G':
				str[i] = 'C';
				break;
		}
	}
	return str;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int run;
	int start;
	string s;
	string comp;
	string res = "";
	for(run=1; run<=5; run++) {
		getline(cin, s);
		start = s.find("TATAAT")+10;
		string temp1 = s.substr(start);
		for(int i=0; i+5<temp1.length()-6; i++) {
			comp = temp1.substr(i, 6);
			string temp2 = temp1.substr(i+5);
			comp = revComplement(comp);
			if(temp2.find(comp)<temp2.length()) {
				res = temp1.substr(0, i);
				break;
			}
		}
		res = complement(res);
		for(int i=0; i<res.length(); i++) {
			if(res[i]=='T') {
				res[i]='U';
			}
		}
		cout << run << ": " << res << endl;
	}
}
