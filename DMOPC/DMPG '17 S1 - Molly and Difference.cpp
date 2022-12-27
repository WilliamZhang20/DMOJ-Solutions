#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, *arr;
  int temp;
  scanf("%d", &n);
  arr = new int[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);
  int d = abs(arr[1]-arr[0]);
  for(int i=2; i<n; i++) {
    temp = abs(arr[i]-arr[i-1]);
    if(temp<d) {
      d = temp;
    }
  }
  cout << d << endl;
}
