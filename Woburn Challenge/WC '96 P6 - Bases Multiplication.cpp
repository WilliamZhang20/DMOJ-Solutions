#include <bits/stdc++.h>
using namespace std;
// bases multiplication

string decimalToAnyBase(int deci, int newBase) {
    string res = "";
    int hold;
    while(deci>=1) {
        hold = deci%newBase;
        res = to_string(hold) + res;
        deci/=newBase;
    }
    return res;
}

int anyBaseToDecimal(string num, int numBase) {
    int deci=0;
    reverse(num.begin(), num.end());
    for(int i=0; i<num.size(); i++) {
        deci += (num[i]-'0')*pow(numBase, i);
    }
    return deci;
}   

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int sets=5;
    while(sets--) {
        string firstNum, secondNum;
        int firstBase, secondBase, endBase;
        cin >> firstNum >> firstBase;
        cin >> secondNum >> secondBase;
        cin >> endBase;
        int firstDeci = anyBaseToDecimal(firstNum, firstBase);
        int secondDeci = anyBaseToDecimal(secondNum, secondBase);
        int product = firstDeci * secondDeci;
        cout << decimalToAnyBase(product, endBase) << endl;
    }
}
