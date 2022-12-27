#include <bits/stdc++.h>

using namespace std;

int main() {
  int num1, num2;
  cin >> num1;
  cin >> num2;
  char str1[num1][41], str2[num2][41];
  for(int i=0; i<num1; i++) {
    cin >> str1[i];
  }
  for(int i=0; i<num2; i++) {
    cin >> str2[i];
  }
  for(int i=0; i<num1; i++) {
    for(int j=0; j<num2; j++) {
      cout << str1[i] << " as " << str2[j] <<endl;
    }
  }
}
