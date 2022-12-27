#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, waitTime;
  int touchTime;
  int alt;
  cin >> h >> waitTime;
  for(int i=1; i<=waitTime; i++) {
    alt= -6*pow(i, 4) + h*pow(i, 3) + 2*pow(i, 2) + i;
    if(alt<=0) {
      cout << "The balloon first touches ground at hour:\n" << i << endl;
      break;
    } else if(i==waitTime) {
      cout << "The balloon does not touch ground in the given time.\n";
    } 
  }
}
