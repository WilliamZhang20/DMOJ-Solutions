#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
  c = tolower(c);
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  string s1, s2, s3, s4;
  getline(cin, s1);
  n = stoi(s1);
  string end1, end2, end3, end4;
  while(n--) {
    getline(cin, s1); transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    getline(cin, s2); transform(s2.begin(), s2.end(), s2.begin(), ::tolower); 
    getline(cin, s3); transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
    getline(cin, s4); transform(s4.begin(), s4.end(), s4.begin(), ::tolower);
    for(int i=s1.length()-1; i>=0; i--) {
      if(isVowel(s1[i]) || s1[i]==' ' || i==0) {
        end1 = s1.substr(i);
        //cout << end1 << endl;
        break;
      }
    }
    for(int i=s2.length()-1; i>=0; i--) {
      if(isVowel(s2[i]) || s2[i]==' ' || i==0) {
        end2 = s2.substr(i);
        //cout << end2 << endl;
        break;
      }
    }
    for(int i=s3.length()-1; i>=0; i--) {
      if(isVowel(s3[i]) || s3[i]==' ' || i==0) {
        end3 = s3.substr(i);
        //cout << end3 << endl;
        break;
      }
    }
    for(int i=s4.length()-1; i>=0; i--) {
      if(isVowel(s4[i]) || s4[i]==' ' || i==0) {
        end4 = s4.substr(i);
        //cout << end4 << endl;
        break;
      }
    }
    if(end2==end1 && end3==end2 && end4==end3) {
      cout << "perfect\n";
    } else if(end2==end1 && end4==end3) {
      cout << "even\n";
    } else if(end1==end3 && end4==end2) {
      cout << "cross\n";
    } else if(end4==end1 && end2==end3) {
      cout << "shell\n";
    } else {
      cout << "free\n";
    }
  }
}
