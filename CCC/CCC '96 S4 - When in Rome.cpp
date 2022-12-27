#include <bits/stdc++.h>

using namespace std;

class Roman {
	friend istream &operator>>(istream&, Roman&);
	friend ostream &operator<<(ostream&, Roman&);
	public:
		Roman(string);
		string operator+(const Roman&); 
		string operator-(const Roman&);
		string operator*(const Roman &);
		string operator/(const Roman&);
		string operator%(const Roman&);
	private:
		int dec=0;
		string numeral;
		string intToRoman(int);
};

istream &operator>>(istream &input, Roman& rm) {
	input >> rm;
	return input;
}

ostream &operator<<(ostream &output, Roman& rm) {
	output << rm.numeral;
	return output;
}

Roman::Roman(string s) : numeral(s) {
	map<char, int> vals = {
		{'I', 1},
	    {'V', 5},
	    {'X', 10},
	    {'L', 50},
	    {'C', 100},
	    {'D', 500},
	    {'M', 1000}
	};
	for(char i: numeral) {
		dec += vals[i];
	}
	for(int i=0; i<numeral.size()-1; i++) {
		if(numeral[i]=='I' && (numeral[i+1]=='V' || numeral[i+1]=='X')) {
			dec-=2;
		} else if(numeral[i]=='X' && (numeral[i+1]=='L' || numeral[i+1]=='C')) {
			dec-=20;
		} else if(numeral[i]=='C' && (numeral[i+1]=='D' || numeral[i+1]=='M')) {
			dec-=200;
		}
	}
}

string Roman::operator+(const Roman& B) {
	// Note: using const reference because I do not want to modify, but I also do not want to make a copy
	int decSum = this->dec + B.dec;
	if(decSum>1000) {
		return "CONCORDIA CUM VERITATE";
	}
	return this->intToRoman(decSum);
}

string Roman::intToRoman(int i) {
	vector<pair<string, int>> dict;
	dict.push_back({"M", 1000});
	dict.push_back({"CM", 900});
	dict.push_back({"D", 500});
	dict.push_back({"CD", 400});
	dict.push_back({"C", 100});
	dict.push_back({"XC", 90});
	dict.push_back({"L", 50});
	dict.push_back({"XL", 40});
	dict.push_back({"X", 10});
	dict.push_back({"IX", 9});
	dict.push_back({"V", 5});
	dict.push_back({"IV", 4});
	dict.push_back({"I", 1});
	string roman_value = "";
	while(i>0) {
		for(auto c: dict) {
			if(c.second <= i) {
				roman_value+=c.first;
				i-=c.second;
				break;
			}
		}
	}
	return roman_value;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		string sum;
		string a, b;
		cin >> sum;
		sum.pop_back();
		for(int i=0; i<sum.length(); i++) {
	    	if(sum[i]=='+') {
	    		a = sum.substr(0, i);
	        	b = sum.substr(i+1);
	        	break;
	      	}
	    }
		Roman A(a), B(b);
		cout << sum << "=" << A + B << '\n';
	}
}
