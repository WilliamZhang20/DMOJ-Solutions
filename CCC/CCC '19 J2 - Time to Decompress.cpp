#include <bits/stdc++.h>

using namespace std;

int main() {
  int l;
  cin >> l;
  int nums[l];
  char ch[l];
  for(int i=0; i<l; i++) {
    cin >> nums[i] >> ch[i];
  }
  for(int i=0; i<l; i++) {
    for(int j=0; j<nums[i]; j++) {
      cout << ch[i];
    }
    cout << endl;
  }
}
