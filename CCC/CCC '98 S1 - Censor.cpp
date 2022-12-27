#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  string s;
  int first;
  getline(cin, s);
  n = stoi(s);
  while(n--) {
    getline(cin, s);
    first = 0;
    for(int j=0; j<s.length(); j++) {
      if(s[j]==' ') {
        if(j-first==4) {
          s[first]='*';
          s[first+1] = '*';
          s[first+2] = '*';
          s[first+3] = '*';
        }
        first = j+1;
      } else if(j==s.length()-1) {
        if(j-first==3) {
          s[first]='*';
          s[first+1] = '*';
          s[first+2] = '*';
          s[first+3] = '*';
        }
      }
    }
    cout << s << endl;
  }
}
