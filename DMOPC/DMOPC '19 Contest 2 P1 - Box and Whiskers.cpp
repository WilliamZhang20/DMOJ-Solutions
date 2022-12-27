#include <bits/stdc++.h>

using namespace std;

// example: 1 2 3 4 5 6 7 8 9 10

double findMedian(int a[], int n) {
  double med;
  sort(a, a+n);

  if(n%2==0) {
    med = (a[n/2-1]+a[n/2])/2.0;
  } else {
    med = a[((n+1)/2)-1];
  }
  return med;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  // temp array to store n/2 elements
  int r = floor(n/2);
  int temp[r];
  
  int min, max;
  double med;
  double q1, q3;
  int j;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  min = *min_element(a, a+n);
  max = *max_element(a, a+n);
  med = findMedian(a, n);
  for(int i=0; i<r; i++) {
    temp[i] = a[i];
  } 
  q1 = findMedian(temp, r);
  j=0;
  if(n%2==0)
    for(int i=r; i<n; i++) {
      temp[j] = a[i];
      j++;
    }
  else
    for(int i=r+1; i<n; i++) {
      temp[j] = a[i];
      j++;
    }
  q3 = findMedian(temp, r);
  cout << fixed;
  cout << min << " " << max << " " << q1 << " " << med << " " << q3 << endl;
}
