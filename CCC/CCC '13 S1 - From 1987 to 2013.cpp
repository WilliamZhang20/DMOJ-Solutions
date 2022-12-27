#include <bits/stdc++.h>

using namespace std;

bool isDistinct(string str) {
  int sz = str.length();
  for(int i=0; i<sz; i++) {
    for(int j=i+1; j<sz; j++) {
      if((str[i]-48)==(str[j]-48)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string s;
  int n;
  cin >> s;
  n=stoi(s);
  n++;
  s = to_string(n);
  while(1) {
    if(!isDistinct(s)) {
      break;
    } 
    n=stoi(s);
    n++;
    s = to_string(n);
  }
  cout << s << endl;
}
