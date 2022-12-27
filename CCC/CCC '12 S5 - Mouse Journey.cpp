#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  int r, c;
  ll **dp;
  cin >> r;
  cin >> c;
  int catR, catC;
  // initializing array
  dp = new ll*[r+1];
  for(int i=0; i<r+1; i++) {
    dp[i] = new ll[c+1] {0};
  }
  int k; // with cats
  cin >> k;
  for(int i=0; i<k; i++) {
    cin >> catR >> catC;
    dp[catR][catC] = -1;
  }
  dp[1][1] = 1;
  for(int row = 1; row<=r; row++) {
    for(int col = 1; col<=c; col++) {
      if(dp[row][col]!=-1 && dp[row-1][col]!=-1) {
        dp[row][col] = dp[row][col] + dp[row-1][col];
      }
      if(dp[row][col]!=-1 && dp[row][col-1]!=-1) {
        dp[row][col] = dp[row][col] + dp[row][col-1];
      }
    }
  }
  /*for(int row = 1; row<=r; row++) {
    for(int col = 1; col<=c; col++) {
      cout << dp[row][col] << " ";
    }
    cout << endl;
  }*/
  cout << dp[r][c] << endl;
}
