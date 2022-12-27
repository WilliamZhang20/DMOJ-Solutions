#include <bits/stdc++.h>

using namespace std;

int crystalsAtX(int m, int x) {
  int power;
  int location;
  if(m>=1) {
    power = pow(5, m-1);
    location = floor(x/power);
    if(location==0 || location==4) {
      return 0;
    } else if(location==1 || location==3) {
      return 1*power + crystalsAtX(m-1, x%power);
    } else if(location==2) {
      return 2*power + crystalsAtX(m-1, x%power);
    }
    return pow(5, m)-1; // if nothing else worked
  }
  return 0;
}

int main() {
  int t;
  int m, x, y;
  cin >> t;
  for(int i=0; i<t; i++) {
    cin >> m >> x >> y;
    if(y<crystalsAtX(m, x)) {
      cout << "crystal\n";
    } else {
      cout << "empty\n";
    }
  }
}
