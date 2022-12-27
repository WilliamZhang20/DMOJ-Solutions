#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  vector<int> arr;
  int input;
  int sum=0;
  cin >> k;
  for(int i=0; i<k; i++) {
    cin >> input;
    if(arr.size()!=0 && input==0) {
      arr.pop_back();
    } else {
      arr.push_back(input);
    }
  }
  for(auto a: arr) {
    sum+=a;
  }
  cout << sum << endl;
}
