#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int medians[n];
  int a[n];
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> a[j];
    }
    sort(a, a+n);
    medians[i] = a[(n-1)/2];
  }
  sort(medians, medians+n);
  cout << medians[(n-1)/2] << endl;
}
