#include <bits/stdc++.h>

using namespace std;

int lcs(int a[], int b[], int m, int n) {
  int LCS_table[m+1][n+1];
  int i, j;
  for(int i=0; i<=m; i++) {
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0) {
        LCS_table[i][j] = 0;
      }
      else if(a[i-1] == b[j-1]) {
        LCS_table[i][j] = LCS_table[i-1][j-1]+1;
      } else {
        LCS_table[i][j] = max(LCS_table[i-1][j], LCS_table[i][j-1]);
      }
    }
  }
  return LCS_table[m][n];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int s1[n], s2[m];
  for(int i=0; i<n; i++) {
    cin >> s1[i];
  }
  for(int j = 0; j<m; j++) {
    cin >> s2[j];
  }
  cout << lcs(s1, s2, n, m) << endl;
}
