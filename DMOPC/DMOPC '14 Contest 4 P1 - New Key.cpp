#include <bits/stdc++.h>

using namespace std;

int findASCII(char c) {
   int i = c;
   return i;
}

int main() {
  string msg;
  cin >> msg;
  for(int i=0; i<msg.size(); i++) {
    if(findASCII(msg[i])>=65 || findASCII(msg[i])==48) {
      msg[i]+=9;
    } else if(findASCII(msg[i])>48) {
      msg[i]+=16;
      }
  }
  cout << msg << endl;
}
