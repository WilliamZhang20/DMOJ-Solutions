#include <bits/stdc++.h>

using namespace std;

int countSetBits(int n)
{
  string s = to_string(n);
  int count = 0;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='1') {
      count++;
    }
  }
  return count;
}

int decimal_to_binary_r(int d) {
  if(d==0) {
    return 0;
  } else {
    return d%2 + 10*decimal_to_binary_r(d/2);
  }
}

int addBit(int n) {
  if(n%2==0) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int hBits;
  for(int i=0; i<5; i++) {
    cin >> n;
    n = decimal_to_binary_r(n);
    hBits = countSetBits(n);
    cout << addBit(hBits) << endl;
  }
}
