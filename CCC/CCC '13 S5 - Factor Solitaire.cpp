#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  int cost=0;
  scanf("%d", &n);
  int r, f, x;
  while(n>1) {
    r=round(sqrt(n))+1;
    f = 2;
    while(f<=r && n%f!=0) {
      f++;
    }
    if(f<n && n%f==0) { // real factor case
      x = n/f;
      n-=x;
      cost+=n/x;
    } else { // the case of n being prime
      n--; 
      cost+=n;
    }
  }
  printf("%d\n", cost);
}
