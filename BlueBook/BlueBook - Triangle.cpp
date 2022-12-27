#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int input;
  cin >> input;
  int arr[input+1][input+1];
  arr[0][0] = 1;
  for(int i=1; i<=input; i++) {
    arr[i][0] = 1;
    for(int j=1; j<i-1; j++) {
      arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
    arr[i][i-1] = 1;
  }
  for(int i=1; i<=input; i++) {
    for(int j=0; j<i; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
