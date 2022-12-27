#include <bits/stdc++.h>

using namespace std;

void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  deque<int> sandwich;
  cin >> n;
  string s;
  cin >> s;
  for(int i=0; i<n; i++) {
    s[i]=='0'? sandwich.push_back(i+1): sandwich.push_front(i+1);
  }
  showdq(sandwich);
}
