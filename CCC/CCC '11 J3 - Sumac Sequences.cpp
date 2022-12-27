#include <iostream>

using namespace std;

int sumac(int t1, int t2, int len) {
  int next = t1-t2;
  len++;
  if(t2<next) {
    return len;
  } else {
    return sumac(t2, next, len);
  }
  return len;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << sumac(a, b, 2) << endl;
}
