#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int t;
    cin >> t;
    map<string, bool> easy; // list of existing japaneasy strings
    easy["a"] = true;
    easy["i"] = true;
    easy["u"] = true;
    easy["e"] = true;
    easy["o"] = true;

    easy["ka"] = true;
    easy["na"] = true;
    easy["ma"] = true;
    easy["ha"] = true;
    easy["ra"] = true;

    easy["ki"] = true;
    easy["ni"] = true;
    easy["mi"] = true;
    easy["hi"] = true;
    easy["ri"] = true;

    easy["ku"] = true;
    easy["nu"] = true;
    easy["mu"] = true;
    easy["fu"] = true;
    easy["ru"] = true;

    easy["ke"] = true;
    easy["ne"] = true;
    easy["me"] = true;
    easy["he"] = true;
    easy["re"] = true;

    easy["ko"] = true;
    easy["no"] = true;
    easy["mo"] = true;
    easy["ho"] = true;
    easy["ro"] = true;
    while(t--) {
        //cout << "Number " << t << "\n";
        string s;
        cin >> s;
        int curr_i = 0;
        while(curr_i<s.length()) {
            if(easy[s.substr(curr_i, 1)]) {
                //cout << "True1 " << s.substr(curr_i, 1) << "\n";
                curr_i++;
            } else if(curr_i<s.length()-1 && easy[s.substr(curr_i, 2)]) {
                //cout << "True " << s.substr(curr_i, 2) << "\n";
                curr_i+=2;
            } else if(curr_i<s.length()) {
                cout << "NO\n";
                break;
            } 
            if(curr_i==s.length()){
                cout << "YES\n";
            }
        }
    }
}
