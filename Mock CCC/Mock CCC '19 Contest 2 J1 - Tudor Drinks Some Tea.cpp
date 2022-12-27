#include <iostream>

using namespace std;

int main() {
  char a[5];
  int numPearls=0;
  int i=0;
  do {
    cin >> a[i];
    if(a[i]=='P') {
      numPearls++;
    }
    i++;
  }
  while(i<5);
  cout << numPearls << endl;
}
