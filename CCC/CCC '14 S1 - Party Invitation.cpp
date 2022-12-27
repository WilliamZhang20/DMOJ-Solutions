#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  int m;
  cin >> k;
  vector<int> a;
  for(int i=0; i<k; i++) {
    a.push_back(i+1);
  }
  cin >> m;
  int r[m];
  for(int i=0; i<m; i++) {
    cin >> r[i];
    for(int j=r[i]-1; j<k; j+=r[i]-1) {
      a.erase(a.begin() + j);
      k--;
    }
  }
  for(int i=0; i<k; i++) {
    if(a[i]!=0) {
      printf("%d\n", a[i]);
    }
  }
}
