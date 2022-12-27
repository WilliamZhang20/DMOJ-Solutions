#include <bits/stdc++.h>

using namespace std;

class ARAR {
	public:
		ARAR(string);
		int toDecimal();
		ARAR addition(ARAR);
		ARAR subtraction(ARAR);
		ARAR multiplication(ARAR);
		ARAR division(ARAR);
		ARAR modulus(ARAR);
	private:
		string num;
		unordered_map<char, int> baseVals;
};

ARAR::ARAR(string s) : num(s) {
	baseVals['I'] = 1;
	baseVals['V'] = 5;
	baseVals['X'] = 10;
	baseVals['L'] = 50;
	baseVals['C'] = 100;
	baseVals['D'] = 500;
	baseVals['M'] = 1000;
}

int ARAR::toDecimal() {
	int res = 0;
	for(int i=0; i<num.size(); i+=2) {
		if(baseVals[num[i+1]]<baseVals[num[i+3]]) {
	    	res-=(num[i]-48)*baseVals[num[i+1]];
	    } else {
	    	res+=(num[i]-48)*baseVals[num[i+1]];
	    }
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string num;
	cin >> num;
	ARAR aromatic(num);
	cout << aromatic.toDecimal() << endl;
}
