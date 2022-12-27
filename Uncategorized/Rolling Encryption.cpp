#include <bits/stdc++.h>
#define MAX_SIZE 125
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int k;
	string str;
	cin >> k;
	cin >> str;
	string res = "";
	int i;
	vector<int> freq(MAX_SIZE, 0);
	for(i=0; i<k && i<str.length(); i++) {
		res+=str[i];
		freq[str[i]]++;
	}
	while(i<str.length()) {
		int maxFreq = *max_element(freq.begin(), freq.end());
		for(int j=1; j<MAX_SIZE; j++) {
			if(freq[j]==maxFreq) {
				int shift = (int(str[i]) + (j-96));
				if(shift>122) {
					shift = 96 + (shift-122);
				}
				res += char(shift);
				break;
			}
		}
		freq[str[i-k]]--;
		freq[str[i]]++;
		i++;
	}
	cout << res << endl;
}
