#include <bits/stdc++.h>

using namespace std;

int fib_rec(int a) {
  if(a==1 || a==2) {
    return 1;
  } else {
    return fib_rec(a-1) + fib_rec(a-2);
  }
}

bool isFaxen(int n, int i=2) {
  if(n==fib_rec(i)) {
    return true;
  } else if(fib_rec(i)>n) {
    return false;
  } else {
    return isFaxen(n, i+1);
  }
}

int findDigits_r(int n) {
  if(n/10==0) {
    return 1;
  } else {
    return 1 + findDigits_r(n/10);
  }
}

int main() {
  int a;
  cin >> a;
  if(isFaxen(findDigits_r(a))) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
}
