#include <bits/stdc++.h>

using namespace std;

bool isConsonant(int ascii) {
  char c = char(ascii);
  return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s;
  getline(cin, s);
  for(int i=0; i<s.length(); i++) {
    string add = "  ";
    if(isConsonant(s[i])) {
      int j = 1;
      int num = int(s[i]);
      while(true) {
        if(num-j>=97 && !isConsonant(num-j)) {
          add[0] = char(num-j);
          break;
        }
        if(num+j<=122 && !isConsonant(num+j)) {
          add[0] = char(num+j);
          break;
        }
        j++;
      }
      j = 1;
      while(num+j<=122 && !isConsonant(num+j)) {
        j++;
      }
      num!=122? add[1] = num+j: add[1] = 122;
      s = s.substr(0, i+1) + add + s.substr(i+1);
      i+=2;
    }
  }
  cout << s << endl;
}
