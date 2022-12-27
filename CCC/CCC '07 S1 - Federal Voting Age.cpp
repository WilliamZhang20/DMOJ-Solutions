#include <iostream>

using namespace std;

int main() {
  int n;
  int year, month, day;
  cin >> n;
  bool canVote[n];
  for(int i=0; i<n; i++) {
    cin >> year >> month >> day;
    if(year<1989) {
      canVote[i]=true;
    } else if(year>1989) {
      canVote[i]=false;
    } else {
      if(month>2) {
        canVote[i]=false;
      } else if(month<2) {
        canVote[i]=true;
      } else if(month==2 && day<=27) {
        canVote[i]=true;
      } else {
        canVote[i]=false;
      }
    }
  }
  for(auto a: canVote) {
    if(a) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
