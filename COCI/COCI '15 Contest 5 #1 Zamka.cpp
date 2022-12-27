#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getSum(int n) { // Found this function from the geeksforgeeks website
  int sum=0;
  while(n!=0) {
    sum = sum + n%10;
    n=n/10;
  }
  return sum;
}

int main() {
  int l, d, x;
  double m, n;
  vector<int> listOfPossible;
  cin >> l >> d >> x;
  for(int i=l; i<=d; i++) {
    if(getSum(i)==x) {
      listOfPossible.push_back(i); 
    }
  }
  m = *max_element(listOfPossible.begin(), listOfPossible.end()); // Used deref. because max_element returns iterator
  n = *min_element(listOfPossible.begin(), listOfPossible.end());
  cout << n << endl;
  cout << m << endl;
}
