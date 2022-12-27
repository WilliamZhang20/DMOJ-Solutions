#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, countS=0, countT=0;
  cin >> n;
  string str;
  for(int i=0; i<n+1; i++) {
    getline(cin, str);
    for(int j=0; j<(str.length()); j++) {
      if(str[j]=='S' || str[j]=='s') {
       countS++;
      }
      else if(str[j]=='T' || str[j]=='t') {
        countT++;
      }
    }
  }
  if(countS>=countT) {
    cout << "French\n";
  }
  else if(countS<countT) {
    cout << "English\n";
  }
}
