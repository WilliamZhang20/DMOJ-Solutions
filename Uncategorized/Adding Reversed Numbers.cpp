#include <bits/stdc++.h>

using namespace std;

string removeZero(string str)
{
    int i = 0;
    while (str[i] == '0')
       i++;
    str.erase(0, i);
    return str;
}

int numReverse_rec(int n) {
  int numDigits = (int) log10(n);
  if(n==0) {
    return 0;
  } else {
    return n%10*pow(10, numDigits) +             numReverse_rec(n/10);
  }
}

int main() {
  int n;
  int a, b;
  int sum;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    a = stoi(removeZero(to_string(a)));
    b = stoi(removeZero(to_string(b)));
    sum = numReverse_rec(a) + numReverse_rec(b);
    sum = numReverse_rec(sum);
    cout << sum << endl;
  }
}
