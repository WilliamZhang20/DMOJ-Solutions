#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
  if(n==1) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

int main() {
  string s;
  cin >> s;
  vector<string> output;
  sort(s.begin(), s.end());
  do {
    output.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  if(output.size() == factorial(s.size())) {
    for(auto a: output) {
      cout << a << endl;
    }
  }
}
