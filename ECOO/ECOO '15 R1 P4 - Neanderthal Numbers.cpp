#include <bits/stdc++.h>
using namespace std;

const set<string> numberWords = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

void solve(string &s) {
    vector<int> dp(s.length()+1);
    dp[s.length()] = 1; // one possible sequence for length 1
    for(int i=int(s.length())-1; i>=0; i--) {
        string next = "";
        for(int j=i; j<int(s.length()); j++) {
            next += s[j];
            if(numberWords.find(next)!=numberWords.end()) {
                dp[i] += dp[j+1];
            }
        }
    }
    cout << dp[0] << "\n";
}   

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int test_case = 10;
    while(test_case--) {
        string str;
        cin >> str;
        solve(str);
    } 
}
