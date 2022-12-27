#include <bits/stdc++.h>
#define sz(x) (int)(x.size())
using namespace std;
// Lexicographically Largest Common Subsequence

const int MAX = 1e6 + 1;
string ans = "";
int n;
int trk[MAX]; // tracks index in each string remaining to be scanned
string s[MAX]; 

bool solve(char ch) {
    int temp[n]; // temp placeholder for ch index
    for(int i=0; i<n; i++) {
        bool exists = 0;
        for(int j=trk[i]; j<sz(s[i]); j++) {
            if(s[i][j]==ch) {
                exists = 1;
                temp[i] = j + 1;
                break;
            } 
        }
        if(!exists) {
            return 0; 
        }
    }
    ans += ch; // adds letters in reverse alphabetic order
    for(int i=0; i<n; i++) {
        trk[i] = temp[i];
    }
    return 1; // run again to look for second or third occurences
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    char letter = 'z';
    while(letter >= 'a') {
        while(solve(letter)) {}
        letter--;
    }
    // check size of result
    if(sz(ans)==0) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
}
