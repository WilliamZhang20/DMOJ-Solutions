#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  scanf("%d", &n);
  int saws[n];
  int logs[n];
  ll energy = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &saws[i]);
  }
  for(int i=0; i<n; i++) {
    scanf("%d", &logs[i]);
  }
  sort(saws, saws+n);
  sort(logs, logs+n);
  for(int i=0; i<n; i++) {
    energy += saws[i]*logs[n-1-i];
  }
  printf("%lld\n", energy);
}
