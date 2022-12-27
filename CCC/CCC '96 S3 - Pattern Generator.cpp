#include <bits/stdc++.h>

using namespace std;

class Combinatorics {
	public:
		Combinatorics(int, int);
		vector<string> patterns();
	private:
		int n;
		int r;
};

Combinatorics::Combinatorics(int n, int r) {
	this->n = n;
	this->r = r;
}

vector<string> Combinatorics::patterns() {
	// Pascal's triangle. nCr = (n-1)C(r-1) + (n-1)C(r)
	vector<string> ans;
	if(n==0) {
		ans.push_back("");
	}
	if(r>0) {
		Combinatorics next(n-1, r-1);
		for(auto& i: next.patterns()) {
			ans.push_back("1" + i);
		}
	}
	if(r<n) {
		Combinatorics next(n-1, r);
		for(auto& i: next.patterns()) {
			ans.push_back("0" + i);
		}
	}
	return ans;
}

void solve_tc(int n, int r) {
	Combinatorics gener(n, r);
	for(auto& i: gener.patterns()) {
		cout << i << endl;
	}
}

int main() {
    int count;
    cin >> count;
    while(count--) {
        int n, k;
        cin >> n >> k;
		cout << "The bit patterns are\n";
		solve_tc(n, k);
		if(count>0) cout << '\n';
    }
}
