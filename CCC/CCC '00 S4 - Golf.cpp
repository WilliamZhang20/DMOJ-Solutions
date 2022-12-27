#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x;
  int n;
  int counter = 5;
  cin >> x;
  cin >> n;
  int clubs[n];
  for(int i=0; i<n; i++) {
    cin >> clubs[i];
  }
  vector<int> memo(x+1);
  for(int i=1; i<=x; i++) {
    memo[i] = 5281;
    for(int j = 0; j<n; j++) {
      if(i>=clubs[j]) {
        memo[i] = min(memo[i], 1 + memo[i-clubs[j]]);
      }
    }
  }
  if(memo[x]==5281) {
    cout << "Roberta acknowledges defeat.\n";
  }
  else {
     cout << "Roberta wins in "<<memo[x]<<" strokes.\n";
  }
}
