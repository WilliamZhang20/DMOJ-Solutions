#include <bits/stdc++.h>

using namespace std;

bool isOkay(char c) {
  int n = int (c);
  if(n<=90 && n>=65) {
    return true;
  } else if(n>=97 && n<=126) {
    return true;
  } else if(n>=48 && n<=57) {
    return true;
  }
  return false;
}

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
      while(!isOkay(s[first]) && first<s.length()) {
        first++; 
      }
      if(!isOkay(s[j])) {
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
