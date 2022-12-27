#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	map<string, char> decoder;
	vector<string> code_list;
	for(int i=0; i<k; i++) {
		char c;
		string code;
		cin >> c >> code;
		decoder[code] = c;
		code_list.push_back(code);
	}
	string sequence;
	cin >> sequence;
	int curr_i = 0;
	while(curr_i<sequence.length()) {
		int search = 1;
		bool canGo = true;
		while(canGo) {
			string curr_search = sequence.substr(curr_i, search);
			for(int i=0; i<code_list.size(); i++) {
				if(curr_search==code_list[i]) {
					cout << decoder[curr_search];
					curr_i += search;
					canGo = false;
					break;
				}
			}
			search++;
		}
	}
	return 0;
}
