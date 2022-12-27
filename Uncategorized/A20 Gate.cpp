#include <bits/stdc++.h>
using namespace std;

string HexToBin(string hexdec)
{
    string res = "";
    long int i = 0;
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            res+="0000";
            break;
        case '1':
            res+="0001";
            break;
        case '2':
            res+="0010";
            break;
        case '3':
            res+="0011";
            break;
        case '4':
            res+="0100";
            break;
        case '5':
            res+="0101";
            break;
        case '6':
            res+="0110";
            break;
        case '7':
            res+="0111";
            break;
        case '8':
            res+="1000";
            break;
        case '9':
            res+="1001";
            break;
        case 'A':
        case 'a':
            res+="1010";
            break;
        case 'B':
        case 'b':
            res+="1011";
            break;
        case 'C':
        case 'c':
            res+="1100";
            break;
        case 'D':
        case 'd':
            res+="1101";
            break;
        case 'E':
        case 'e':
            res+="1110";
            break;
        case 'F':
        case 'f':
            res+="1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
    return res;
}

string binToHex(string hex) {
  string temp;
  string bin = "";
  int sz1 = hex.size();
  int check = 0;
  while(check<sz1) {
    temp = hex.substr(check, 4);
    if(temp=="0000") {
      bin+="0";
    } else if(temp=="0001") {
      bin+="1";
    } else if(temp=="0010") {
      bin+="2";
    } else if(temp=="0011") {
      bin+="3";
    } else if(temp=="0100") {
      bin+="4";
    } else if(temp=="0101") {
      bin+="5";
    } else if(temp=="0110") {
      bin+="6";
    } else if(temp=="0111") {
      bin+="7";
    } else if(temp=="1000") {
      bin+="8";
    } else if(temp=="1001") {
      bin+="9";
    } else if(temp=="1010") {
      bin+="A";
    } else if(temp=="1011") {
      bin+="B";
    } else if(temp=="1100") {
      bin+="C";
    } else if(temp=="1101") {
      bin+="D";
    } else if(temp=="1110") {
      bin+="E";
    } else if(temp=="1111") {
      bin+="F";
    }
    check+=4;
  }
  return bin;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	string hex;
	string bin;
  int temp;
  string low;
	cin >> n;
	while(n--) {
		cin >> hex;
        bin = HexToBin(hex);
        temp = bin.size();
        if(bin[temp-21]=='0') {
            cout << hex << endl;
        } else if(bin[temp-21]=='1') {
            low = bin;
            low[temp-21] = '0';
            cout << binToHex(low) << " ";
            cout << hex << endl;
        }
	}
}
