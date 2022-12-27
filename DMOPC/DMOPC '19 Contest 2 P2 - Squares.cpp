#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[501][501]; 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int m;
  cin >> m;
  int costs[n+1][m+1];
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> costs[i][j];
    }
  }
  // working backwards from the end to compute minimum total cost
  for(int i=n; i>0; i--) {
    for(int j=m; j>0; j--) {
      if(i==n && j==m) {
        dp[i][j] = costs[i][j];
      } else {
        dp[i][j] = LONG_LONG_MAX;
        if(i!=n) {
          dp[i][j] = min(dp[i][j], dp[i+1][j] + costs[i][j]);
        }
        if(j!=m) {
          dp[i][j] = min(dp[i][j], dp[i][j+1] + costs[i][j]);
        }
      }
    /*for(int k=1; k<=n; k++) {
        for(int p=1; p<=m; p++) {
          cout << dp[k][p] << " ";
        } cout << endl;
      }*/
    }
  }
  cout << dp[1][1] << endl;
}
