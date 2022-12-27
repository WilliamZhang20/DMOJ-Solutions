#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  int p, a;
  ll cost = 0;
  pair<int, int> factories[200000];
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++) {
    scanf("%d%d", &p, &a);
    factories[i] = make_pair(p, a);
  }
  sort(factories, factories+n);
  for(int i=0; i<n; i++) {
    cost += min(factories[i].second, m) * factories[i].first; // adding (cost per box * as many boxes as possible)
    m -= factories[i].second; // subtracting from boxes that we stil need to buy
    if(m<=0) break;
  }
  printf("%lld\n", cost);
}
