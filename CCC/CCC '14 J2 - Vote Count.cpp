#include <bits/stdc++.h>

using namespace std;

int main() {
  int voteA=0, voteB=0, v;
  string input;
  cin >> v;
  cin >> input;
  for(int i=0; i<v; i++) {
    if(input[i]=='A') {
      voteA++;
    }
    else if(input[i]=='B') {
      voteB++;
    }
  }
  if(voteA>voteB) {
    cout << "A" << endl;
  }
  else if(voteB>voteA) {
    cout << "B" << endl;
  }
  else if(voteA==voteB) {
    cout << "Tie" << endl;
  }
}
