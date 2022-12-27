#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = 1e9+7;

int main() {
  int r, c;
  ll **dp;
  cin >> r;
  cin >> c;
  // initializing array
  dp = new ll*[r+1];
  for(int i=0; i<r+1; i++) {
    dp[i] = new ll[c+1];
  }
  char ch;
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cin >> ch;
      if(ch=='#') {
        dp[i][j]=-1;
      } else {
        dp[i][j]=0;
      }
    }
  }
  dp[1][1] = 1;
  for(int row = 1; row<=r; row++) {
    for(int col = 1; col<=c; col++) {
      if(dp[row][col]!=-1 && dp[row-1][col]!=-1) {
		    dp[row][col] %= MOD;
		    dp[row-1][col] %= MOD;
        dp[row][col] = dp[row][col] + dp[row-1][col];
		    dp[row][col] %= MOD;
      }
      if(dp[row][col]!=-1 && dp[row][col-1]!=-1) {
        dp[row][col] %= MOD;
        dp[row][col-1] %= MOD;
        dp[row][col] = dp[row][col] + dp[row][col-1];
        dp[row][col] %= MOD;
      }
    }
  }
  cout << dp[r][c] << endl;
}
