#include <iostream>

using namespace std;

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int lengths[n];
  int start, end;
  for(int i=0; i<n; i++) {
    cin >> start >> end;
    lengths[i]=end-start;
  }
  int max=lengths[0];
  for(int a: lengths) {
    if(a>max) {
      max=a;
    }
  }
  cout << max << "\n";
}
