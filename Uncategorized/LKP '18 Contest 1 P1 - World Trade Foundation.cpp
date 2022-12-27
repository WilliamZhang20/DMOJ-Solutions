#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  int amount=0;
  int counter = 0;
  cin >> n >> k;
  int coins[n];
  for(int i=0; i<n; i++) {
    cin >> coins[i];
  }
  int j = n-1;
  while(j>=0) {
    if(coins[j]<=k-amount) {
      amount+=coins[j];
      counter++;
    } else {
      j--;
    }
  }
  if(amount!=k) {
    cout << "-1\n";
  } else {
    cout << counter << endl;
  }
}
