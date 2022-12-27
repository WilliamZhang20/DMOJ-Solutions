#include <bits/stdc++.h>

using namespace std;

int lis(int arr[], int n) {
  int res[n];
  res[0] = 1;
  for(int i=1; i<n; i++) {
    res[i] = 1;
    for(int j=0; j<i; j++) {
      if(arr[i]>arr[j] && res[i]<res[j]+1) {
        res[i] = res[j]+1; 
      }
    }
  }
  return *max_element(res, res+n);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  cout << lis(a, n) << endl;
}
