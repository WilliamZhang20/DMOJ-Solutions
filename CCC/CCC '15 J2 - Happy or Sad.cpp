#include <bits/stdc++.h>

using namespace std;

string happySad(string s) 
{
  int size = s.length(); 
  int numHappy=0, numSad = 0;
  for(int i = 0; i < size; ++i)
    {
        if(s[i] == ':' && s[i + 1] == '-')
        {
            if(s[i + 2] == ')')
                numHappy++;
            else if(s[i + 2] == '(')
                numSad++;
        }
    }
    if(!(numHappy || numSad))
        return "none";
    if(numHappy == numSad)
        return "unsure";
    if(numHappy > numSad)
        return "happy";
    return "sad";
}

int main() 
{
  string line;
  getline(cin, line);
  line = happySad(line);
  cout << line << endl;
}
