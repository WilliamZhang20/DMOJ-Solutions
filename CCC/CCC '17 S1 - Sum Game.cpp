#include <iostream>
// prefix sum array used
using namespace std;

int main() {
  int n;
  int input;
  int largest = 0;
  cin >> n;
  int swift[n];
  int sema[n];
  cin >> swift[0];
  for(int i=1; i<n; i++) {
    cin >> input;
    swift[i] = swift[i-1] + input;
  }
  cin >> sema[0];
  if(sema[0]==swift[0]) {
    largest = 1;
  }
  for(int i=1; i<n; i++) {
    cin >> input;
    sema[i] = sema[i-1] + input;
    if(sema[i] == swift[i]) {
      largest = i+1;
    }
  }
  cout << largest << endl;
}
