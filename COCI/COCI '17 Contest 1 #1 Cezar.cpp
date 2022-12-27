#include <bits/stdc++.h>

using namespace std;

int sum = 0;
int sumArr_rec(int a[], int n) {
  int val = n-1;
  if(n==1) {
    return a[0];
  } else {
    n--;
    return a[val]+sumArr_rec(a, n);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int s;
  cin >> n;
  int a[n];
  int x; // difference between 21 and curr sum
  int numBelow=0, numAbove=0;
  int deck[] = {4, 4, 4, 4, 4, 4, 4, 4, 16, 4}; // number of cards worth each value (in deck[8], it shows that 16 cards have value of 10)
  for(int i=0; i<n; i++) {
    cin >> a[i];
    deck[a[i]-2]--;
  }
  s = sumArr_rec(a, n);
  x = 21 - s;
  for(int i=0; i<10; i++) {
    if(i+2<=x) {
      numBelow+=deck[i];
    } else if(i+2>x) {
      numAbove+=deck[i];
    }
  }
  numAbove>=numBelow ? cout << "DOSTA\n": cout << "VUCI\n";
}
