#include <bits/stdc++.h>

using namespace std;

int main() {
  string str[1001], out[1001];
  int i=0;
  while(1) {
    cin >> str[i];
    if(str[i]=="TTYL") {
      break;
    }
    i++;
  }
  int sz = i+1;
  for(i=0; i<sz; i++) {
    if(str[i]=="CU") {
      out[i]="see you";
    }
    else if(str[i]==":-)") {
      out[i]="I'm happy";
    }
    else if(str[i]==":-(") {
      out[i]="I'm unhappy";
    }
    else if(str[i]==";-)") {
      out[i]="wink";
    }
    else if(str[i]==":-P") {
      out[i]="stick out my tongue";
    }
    else if(str[i]=="(~.~)") {
      out[i]="sleepy";
    }
    else if(str[i]=="TA") {
      out[i]="totally awesome";
    }
    else if(str[i]=="CCC") {
      out[i]="Canadian Computing Competition";
    }
    else if(str[i]=="CUZ") {
      out[i]="because";
    }
    else if(str[i]=="TY") {
      out[i]="thank-you";
    }
    else if(str[i]=="YW") {
      out[i]="you're welcome";
    }
    else if(str[i]=="TTYL") {
      out[i]="talk to you later";
    }
    else {
      out[i]=str[i];
    }
  }
  for(i=0; i<sz; i++) {
    cout << out[i] << endl;
  }
}
