#include <iostream>

using namespace std;

bool isRotatable(int n) {
  int i=0;
  int a[n];
  int x = n;
  bool okay = true;
  while(x!=0) {
    i++;
    a[i]=x%10;
    x/=10;
  }
  for(int j=1; j<=i; j++) {
    if((a[j]==0 && a[i-j+1]==0) || (a[j] == 1 && a[i-j+1]==1) || (a[j]==8 && a[i - j + 1] == 8) || (a[j] == 9 && a[i - j + 1] == 6) || (a[j] == 6 && a[i - j + 1] == 9)) {

    } else {
      okay = false;
    }
  }
  return okay;
}

int main() {
  int count = 0;
  int m, n;
  cin >> m;
  cin >> n;
  for(int i=m; i<=n; i++) {
    if(isRotatable(i)) {
      count++;
    }
  }
  cout << count << endl;
}
