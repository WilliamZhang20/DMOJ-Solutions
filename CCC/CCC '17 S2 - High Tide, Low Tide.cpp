#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int b, key;  // for sorting
  int middle;
  int counter = 0;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  // insertion sort the array
  for(int j=1; j<n; j++) {
    key = a[j]; 
    b = j-1;
    while(b>=0 && a[b]>key) {
      a[b+1]=a[b]; 
      b--; 
    }
    a[b+1]=key;
  }
  if(n%2==0) {
    middle = n/2-1;
    while(counter<floor(n/2)) {
      cout << a[middle-counter] << " ";
      counter++;
      cout << a[middle+counter] << " ";
    }
  } else {
    middle = (n-1)/2;
    while(counter<=floor(n/2)) {
      cout << a[middle-counter] << " ";
      counter++;
      if(counter<=floor(n/2))
        cout << a[middle+counter] << " ";
    }
  }
  cout << '\n';
}
