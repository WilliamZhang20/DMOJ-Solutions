#include <bits/stdc++.h>

using namespace std;

int *m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int q;
  int a, b;
  int total;
  scanf("%d", &n);
  scanf("%d", &q);
  m = new int[n+1] {0};
  scanf("%d", &m[1]);
  total = m[1];
  for(int i=2; i<=n; i++) {
    scanf("%d", &m[i]);
    total += m[i];
    m[i]+=m[i-1];
  }
  for(int i=0; i<q; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", m[n]-(m[b]-m[a-1]));
  }
}
