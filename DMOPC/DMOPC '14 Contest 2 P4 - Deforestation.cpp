#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int *m;
void prefix_sum_array(int);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int q;
  int a, b;
  scanf("%d", &n);
  m = new int[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &m[i]);
  }
  prefix_sum_array(n);
  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    scanf("%d %d", &a, &b);
    if(a==0) {
      printf("%d\n", m[b]);
    } else {
      printf("%d\n", m[b]-m[a-1]);
    }
  }
}

void prefix_sum_array(int n)
{
  for(int i=1; i<n; i++) {
    m[i] = m[i] + m[i-1];
  }
}
