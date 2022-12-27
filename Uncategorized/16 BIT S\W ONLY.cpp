#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long int a[n], b[n], p[n];
  string output[n];
  for(int i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    if(a[i]*b[i]==p[i]) {
      output[i] = "POSSIBLE DOUBLE SIGMA";
    } else {
      output[i] = "16 BIT S/W ONLY";
    }
  }
  for(string n: output) {
    cout << n << endl;
  }
}
