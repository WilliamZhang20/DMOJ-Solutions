#include <bits/stdc++.h>

using namespace std;

int main() {
  string str;
  cin >> str;
  int len = str.length(), count=0;
  for(int i=0; i<len; i++) {
    if(str[i]=='I' || str[i]=='O' || str[i]=='S' || str[i]=='H' || str[i]=='Z' || str[i]=='X' || str[i]=='N') {
      count++;
    }
  }
  if(count==len) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}
