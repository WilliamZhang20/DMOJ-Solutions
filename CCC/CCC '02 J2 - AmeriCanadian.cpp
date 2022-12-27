#include <iostream>
#include <vector>

using namespace std;

int main() {
  string amWord;
  vector<string> words;
  while(true) {
    cin >> amWord;
    if(amWord=="quit!") {
      break;
    } else {
      words.push_back(amWord);
    }
  }
  int sz = words.size();
  int wordSz;
  for(int i=0; i<sz; i++) {
    wordSz = words[i].size();
    if(wordSz>3 && words[i][wordSz-1]=='r' && words[i][wordSz-2]=='o' && words[i][wordSz-3]!='a' && words[i][wordSz-3]!='e' && words[i][wordSz-3]!='i' && words[i][wordSz-3]!='o' && words[i][wordSz-3]!='u' && words[i][wordSz-3]!='y') {
      words[i].pop_back();
      words[i].insert(words[i].begin()+wordSz-1, 'u');
      words[i].insert(words[i].begin()+wordSz, 'r');
    }
  }
  for(string a: words) {
    cout << a << endl;
  }
}
