#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, h;
  int breaks=0;
  cin >> n >> m >> h;
  int b[n];
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  for(int i=n-2; i>=0; i--) {
    if(b[i+1]-b[i]>h) {
      while(b[i+1]-b[i]>h) {
        b[i]+=m;
        breaks++;
      }
    }
  }
  cout << breaks << endl;
}
