#include <iostream>

using namespace std;

int main() {
  int square[4][4];
  int sum=0;
  bool magic = true;
  int tempSum1, tempSum2;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      cin >> square[i][j];
    }
  }
  for(int i=0; i<4; i++) {
    sum += square[0][i];
  }
  for(int i=1; i<4; i++) {
    tempSum1=0, tempSum2=0;
    for(int j=0; j<4; j++) {
      tempSum1+=square[i][j];
      tempSum2+=square[j][i];
    }
    if(tempSum1!=sum || tempSum2!=sum) {
      magic = false;
      break;
    }
  }
  if(magic)
    cout << "magic\n";
  else
    cout << "not magic\n";
}
