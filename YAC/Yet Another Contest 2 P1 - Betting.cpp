#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  double a, b, c, d;
  double k1, k2;
  double average;
  cin >> t;
  while(t--) {
    cin >> a >> b >> c >> d;
    if((b-a)*(d-c)>a*c) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
  }
}
