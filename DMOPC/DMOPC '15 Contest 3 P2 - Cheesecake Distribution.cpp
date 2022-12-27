#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  long long int s=0;
  long long int t=0;
  cin >> n;
  long long int arr[n];
  for(long long int i=0; i<n; i++) {
    cin >> arr[i];
    s+=arr[i];
  }
  if(s%n!=0) {
    cout << "Impossible\n";
  } else {
    for(long long int i=0; i<n; i++) {
      t+=abs(arr[i]-(s/n));
    } 
    t/=2;
    cout << t << endl;
  }
}
