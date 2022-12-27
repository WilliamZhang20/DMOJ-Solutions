#include <bits/stdc++.h>

using namespace std;

int findCardScore(char c) {
  int points=0;
  if(c=='J') {
    return 1;
  } else if(c=='Q') {
    return 2;
  } else if(c=='K') {
    return 3;
  } else if(c=='A') {
    return 4;
  }
  return 0;
}

int suitSizePoints(int sz) {
  if(sz==0) {
    return 3;
  } else if(sz==1) {
    return 2;
  } else if(sz==2) {
    return 1;
  } 
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int len = s.length();
  vector<char> clubs, diamonds, hearts, spades;
  int cScore=0, dScore=0, hScore=0, sScore=0;
  for(int i=0; i<len; i++) {
       if(s[i]=='C') {
         while(s[i+1]!='D') {
            clubs.push_back(s[i+1]);
            cScore+=findCardScore(s[i+1]);
            i++;
         }
       }  else if(s[i]=='D') {
         while(s[i+1]!='H') {
            diamonds.push_back(s[i+1]);
            dScore+=findCardScore(s[i+1]);
            i++;
         }
       }  else if(s[i]=='H') {
         while(s[i+1]!='S') {
            hearts.push_back(s[i+1]);
            hScore+=findCardScore(s[i+1]);
            i++;
         }
       }   else if(s[i]=='S') {
         while(s[i+1]!='\0') {
            spades.push_back(s[i+1]);
            sScore+=findCardScore(s[i+1]);
            i++;
         }
       }
  }
  cScore+=suitSizePoints(clubs.size());
  dScore+=suitSizePoints(diamonds.size());
  hScore+=suitSizePoints(hearts.size());
  sScore+=suitSizePoints(spades.size());
  int spacesLeft = 24;
  cout << "Cards Dealt              Points\n";
  cout << "Clubs ";
  for(int i=0; i<clubs.size(); i++) {
    cout << clubs[i] << " ";
    spacesLeft-=2;
  }
  for(int i=0; i<spacesLeft; i++) {
    cout << " ";
  }
  cScore>=10? cout << " " << cScore << endl: cout << cScore << endl;
  // printing diamonds
  spacesLeft = 21;
  cout << "Diamonds ";
  for(int i=0; i<diamonds.size(); i++) {
    cout << diamonds[i] << " ";
    spacesLeft-=2;
  }
  for(int i=0; i<spacesLeft; i++) {
    cout << " ";
  }
  dScore>=10? cout << " " << dScore << endl: cout << dScore << endl;
  // printing hearts
  spacesLeft = 23;
  cout << "Hearts ";
  for(int i=0; i<hearts.size(); i++) {
    cout << hearts[i] << " ";
    spacesLeft-=2;
  }
  for(int i=0; i<spacesLeft; i++) {
    cout << " ";
  }
  hScore>=10? cout << " " << hScore << endl: cout << hScore << endl;
  // printing spades
  spacesLeft = 23;
  cout << "Spades ";
  for(int i=0; i<spades.size(); i++) {
    cout << spades[i] << " ";
    spacesLeft-=2;
  }
  for(int i=0; i<spacesLeft; i++) {
    cout << " ";
  }
  sScore>=10? cout << " " << sScore << endl: cout << sScore << endl;
  // print total
  cout << "                       Total ";
  cout << cScore + dScore + hScore + sScore << endl;
}
