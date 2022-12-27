#include <bits/stdc++.h>

using namespace std;

int n=1;
int modInverse(int x, int m) {
  if(n>=m) {
    return 0;
  } else if((x*n)%m==1) {
    return n;
  } else {
    n++;
    return modInverse(x, m);
  }
}

int main() {
  int x;
  int m;
  cin >> x >> m;
  int n = modInverse(x, m);
  if(n==0) {
    cout << "No such integer exists.\n";
  } else {
    cout << n << endl;
  }
}
