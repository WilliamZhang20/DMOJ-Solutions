#include<bits/stdc++.h>
using namespace std;

string findSum(string str1, string str2)
{
	if (str1.length() > str2.length()) {
		swap(str1, str2);
	}
	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i=0; i<n1; i++)
	{
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}

	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	if (carry) {
		str.push_back(carry+'0');
	}
	reverse(str.begin(), str.end());
	while(str[0]=='0' && str.size()>1) {
		str.erase(0, 1);
	}
	return str;
}

string abs(string s) {
	if(s[0] == '-') {
		s.erase(0, 1);
		return s;
	}
	return s;
}

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2) {
        return true;
	}
    if (n2 < n1) {
        return false;
	}
 
    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i]) {
            return true;
		}
        else if (str1[i] > str2[i]) {
            return false;
		}
	}
    return false;
}


string findDiff(string str1, string str2)
{
	if (isSmaller(str1, str2))
        swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n2; i++) {

		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		str.push_back(sub + '0');
	}

	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);

		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());
	while(str[0]=='0' && str.size()>1) {
		str.erase(0, 1);
	}
	return str;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	string str1;
	string str2;
	bool b1, b2;
	while(n--) {
		cin >> str1 >> str2;
		b1 = true;
		b2 = true;
		if(str1[0]=='-') {
			b1 = false;
		}
		if(str2[0]=='-') {
			b2 = false;
		}
		if(b1 && b2) {
			cout << findSum(str1, str2) << endl;
		} else {
			if(b1 && !b2) {
				str2 = abs(str2);
				if(isSmaller(str1, str2)) {
					cout << "-";
				}
				cout << findDiff(str1, str2) << endl;
			} else if(b2 && !b1) {
				str1 = abs(str1);
				if(isSmaller(str2, str1)) {
					cout << "-";
				}
				string res = findDiff(str1, str2);
				cout << res << endl;
			} else {
				cout << "-" << findSum(abs(str1), abs(str2)) << endl;
			}
		}
	}
	return 0;
}
