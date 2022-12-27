#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int input;
  int n;
  int cost = 0;
  cin >> n;
  vector<int> books;
  for(int i=0; i<n; i++) {
    cin >> input;
    books.push_back(input);
  }
  sort(books.begin(), books.end());
  int j=n-1;
  while(j>=0) {
    cost+=books[j];
    books.pop_back();
    j--;
    if(j>=0) {
      cost+=books[j];
      books.pop_back();
      j--;
      if(j>=0) {
        books.pop_back();
        j--;
      }
    }
  }
  cout << cost << endl;
}
