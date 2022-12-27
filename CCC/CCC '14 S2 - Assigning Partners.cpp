#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  bool isGood=true;
  scanf("%d", &n);
  string a[n], b[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(a[j]==b[i] && b[j]!=a[i]) {
        isGood=false;
      } else if(a[j]!=b[i] && b[j]==a[i]) {
        isGood=false;
      }
    }
    if(a[i]==b[i]) {
      isGood=false;
      break;
    }
  }
  if(isGood==true) {
    cout << "good\n";
  } else {
    cout << "bad\n";
  }
}
