#include <bits/stdc++.h>

using namespace std;

int main() {
  int run = 5;
  string num;
  int res;
  while(run--) {
    res = 0;
    cin >> num;
    for(int i=0; i<num.size(); i++) {
      switch(num[i]) {
        case 'M':
          res+=1000;
          break;
        case 'D':
          if(num[i+1]=='M') {
            res+=500;
            i++;
          } else {
            res+=500;
          }
          break;
        case 'C':
          if(num[i+1]=='D') {
            res+=400;
            i++;
          } else if(num[i+1]=='M') {
            res+=900;
            i++;
          } else {
            res+=100;
          }
          break;
        case 'L':
          if(num[i+1]=='C') {
            res+=50;
            i++;
          } else if(num[i+1]=='D') {
            res+=450;
            i++;
          } else if(num[i+1]=='M') {
            res+=950;
            i++;
          } else {
            res+=50;
          }
          break;
        case 'X':
          if(num[i+1]=='L') {
            res+=40;
            i++;
          } else if(num[i+1]=='C') {
            res+=90;
            i++;
          } else if(num[i+1]=='D') {
            res+=490;
            i++;
          } else if(num[i+1]=='M') {
            res+=990;
            i++;
          } else {
            res+=10;
          }
          break;
        case 'V':
          if(num[i+1]=='X') {
            res+=5;
            i++;
          } else if(num[i+1]=='L') {
            res+=45;
            i++;
          } else if(num[i+1]=='C') {
            res+=95;
            i++;
          } else if(num[i+1]=='D') {
            res+=495;
            i++;
          } else if(num[i+1]=='M') {
            res+=995;
            i++;
          } else {
            res+=5;
          }
          break;
        case 'I':
          if(num[i+1]=='V') {
            res+=4;
            i++;
          } else if(num[i+1]=='X') {
            res+=9;
            i++;
          } else if(num[i+1]=='L') {
            res+=49;
            i++;
          } else if(num[i+1]=='C') {
            res+=99;
            i++;
          } else if(num[i+1]=='D') {
            res+=499;
            i++;
          } else if(num[i+1]=='M') {
            res+=999;
            i++;
          } else {
            res++;
          }
          break;
      }
    }
    cout << res << endl;
  }
}
