#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

ll disks[] = {1, 5, 10, 50, 100, 500, 1000};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll d;
  ll output[7] = {0};
  scanf("%lld", &d);
  for(int i=6; i>=0; i--) {
    output[i]+=floor(d/disks[i]);
    d-=output[i]*disks[i];
  }
  for(int i=0; i<7; i++) {
    cout << output[i] << " ";
  }
  cout << '\n';
}
