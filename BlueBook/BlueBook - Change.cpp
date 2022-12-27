#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  int money;
  string output;
  bool canFit=true;
  int numPennies=0, numNickels=0, numDimes=0, numQuarters=0;
  int org;
  cin >> money;
  org = money;
  while(canFit) {
    if(money-25>=0) {
      money-=25;
      numQuarters++;
    } else if(money-10>=0) {
      money-=10;
      numDimes++;
    } else if(money-5>=0) {
      money-=5;
      numNickels++;
    } else if(money-1>=0) {
      money--;
      numPennies++;
    } else {
      canFit=false;
    }
  }
  cout << org << " cent";
  if(org>1) cout << "s";
  cout << " requires ";
  if(numQuarters>0) {
    cout << numQuarters << " quarter";
    if(numQuarters>1) cout << "s";
  }
  if(numDimes>0) {
    if(numQuarters>0 || numQuarters>0) cout << ", ";
    cout << numDimes  << " dime";
    if(numDimes>1) cout << "s";   
  } 
  if(numNickels>0) {
    if(numDimes>0 || numQuarters>0) cout << ", ";
    cout << numNickels << " nickel";
    if(numNickels>1) cout << "s"; 
  }
  if(numPennies>0) {
    if(numNickels>0 || numDimes>0 || numQuarters>0) cout << ", ";
    cout << numPennies << " cent";
    if(numPennies>1) cout << "s";
  }
  cout << ".\n";
}
