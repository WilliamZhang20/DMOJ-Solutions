#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  array<int, 10> list;
  list.fill(0);
  int input;
  int mode=0;
  int maxFreq;
  for(int i=0; i<n; i++) {
    cin >> input;
    list[input-1]++;
  }
  maxFreq = list[0];
  for(int i=0; i<10; i++)
   {
    if(maxFreq < list[i])
     maxFreq = list[i];
   }
  for(int i=9; i>=0; i--) {
    if(list[i]==maxFreq) {
      mode = i+1;
    }
  }
  cout << mode << endl;
}
