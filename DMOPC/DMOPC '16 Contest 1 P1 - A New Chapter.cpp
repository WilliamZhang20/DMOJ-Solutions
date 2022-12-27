#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  int output=0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]%2==i%2) {
      output++;
    }
  }
  cout << output << endl;
}
