#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	int count1 = 0; // count multiples of 3
	int count2 = 0; 
	int count3 = 0;
	vector<int> a; // 1's
	vector<int> b; // 2's
	vector<int> c; // end result
	cin >> n;
	while(n--) {
		int elem;
		cin >> elem;
		if(elem%3==0) {
			count1++;
			c.push_back(elem);
		} else if(elem%3==1) {
			a.push_back(elem);
			count2++;
		} else if(elem%3==2) {
			b.push_back(elem);
			count3++;
		}
	}
	int remaining=c.size()-1;
	if(count1-(count2+count3)>=2) {
		cout << "impossible\n";
	} 
	else if(count1==0) {
		if(count2>0 && count3>0) {
			cout << "impossible\n";
		} else if(count3==0 && count2>0) {
			for(int i=0; i<a.size(); i++) {
				cout << a[i] << " ";
			} cout << endl;
		} else {
			for(int i=0; i<b.size(); i++) {
				cout << b[i] << " ";
			} cout << endl;
		}
	}
	else {
		for(int i=1; i<int(c.size()); i+=2) {
			if(remaining>2) {
				if(!a.empty()) {
					c.insert(c.begin()+i, a[0]);
					a.erase(a.begin());
				} else {
					c.insert(c.begin()+i, b[0]);
					b.erase(b.begin());
				}
			} else if(remaining==2) {
				int count = 0;
				if(a.empty() && !b.empty()) {
					while(b.size()>1) {
						c.insert(c.begin()+i, b[0]);
						b.erase(b.begin());
						count++;
					}
				} else if(b.empty() && !a.empty()) {
					while(a.size()>1) {
						c.insert(c.begin()+i, a[0]);
						a.erase(a.begin());
						count++;
					}
				} else {
					while(!a.empty()) {
						c.insert(c.begin()+i, a[0]);
						a.erase(a.begin());
						count++;
					}
				}
				while(count>=2) {
					i++;
					count--;
				}
			} else if(remaining==1) {
				int count = 0;
				if(a.empty()) {
					while(!b.empty()) {
						c.insert(c.begin()+i, b[0]);
						b.erase(b.begin());
						count++;
					}
				} else {
					while(!a.empty()) {
						c.insert(c.begin()+i, a[0]);
						a.erase(a.begin());
						count++;
					}
				}
				while(count>=2) {
					i++;
					count--;
				}
			}
			remaining--;
		}
		while(!a.empty()) {
			c.insert(c.begin(), a[0]);
			a.erase(a.begin());
		}
		while(!b.empty()) {
			c.push_back(b[0]);
			b.erase(b.begin());
		}
		for(int i=0; i<int(c.size()); i++) {
			cout << c[i] << " ";
		} cout << "\n";
	}
}
