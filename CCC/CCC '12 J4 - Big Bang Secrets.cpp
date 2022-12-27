#include <iostream>
#include <string>

using namespace std;

int main() {
  int k, temp;
  string sequence, word;
  cin >> k;
  cin >> sequence;
  for(int i=0; i<sequence.length(); i++) {
    temp = int(sequence[i])-(3*(i+1)+k);
    if(temp<65) {
      temp = 90-(64-temp);
    }
    word[i]=temp;
    printf("%c", word[i]);
  }
  cout << endl;
  return 0;
}
