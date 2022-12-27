#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int minimum;
  int maximum;
  int s;
  cin >> n;
  pair<int, int> pass[100000];
  for(int i=0, on, off; i<n-1; i++) {
    cin >> on >> off;
    pass[i] = make_pair(on, off);
  }
  s = pass[0].first;
  minimum = s;
  maximum = s;
  int numPassengers = s;
  for(int i=1; i<n-1; i++) {
    maximum+=min(0, numPassengers-maximum-pass[i].second);
    numPassengers += pass[i].first-pass[i].second;
    minimum-=pass[i].second;
  }
  cout << max(minimum, 0) << endl;
  cout << maximum << endl;
}
