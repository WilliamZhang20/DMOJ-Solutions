#include <bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;
// Binary Index Tree Test

class BIT { // BIT - binary indexed tree
	public:
		BIT(int a[], int n);
		void add(int, int);
		ll rangeSum(int, int);
		void incr_freq(int);
		void decr_freq(int);
		int numFreq(int);
	private:
		vector<ll> BITree;
		vector<ll> freq;
		int sz;
		ll query(int);
};

BIT::BIT(int a[], int n) {
	sz = n;
	BITree.assign(n+1, 0);
	freq.assign(MAX+1, 0);
	for(int i=1; i<=n; i++) {
		add(i, a[i]);
		incr_freq(a[i]);
	}
}

ll BIT::query(int k) { // prefix sum query
	ll s = 0;
	while(k>=1) {
		s += BITree[k];
		k -= k&-k;
	}
	return s;
}

ll BIT::rangeSum(int a, int b) {
	return query(b)-query(a-1);
}

void BIT::add(int index, int val) { 
	while(index<=sz) {
		BITree[index] += val;
		index += index & (-index);
	}
}

void BIT::incr_freq(int val) {
	while(val<=MAX) {
		freq[val]++;
		val += val & (-val);
	}
}

void BIT::decr_freq(int val) {
	while(val<=MAX) {
		freq[val]--;
		val += val & (-val);
	}
}

int BIT::numFreq(int find) {
	int res = 0;
	while(find>0) {
		res += freq[find];
		find -= find & (-find);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m;
	char c;
	int tmp1, tmp2;
	int a[100001] {0};
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	BIT tree(a, n);
	while(m--) {
		cin >> c;
		switch(c) {
			case 'C':
				cin >> tmp1 >> tmp2;
				tree.add(tmp1, tmp2-a[tmp1]); 
				tree.incr_freq(tmp2);
				tree.decr_freq(a[tmp1]);
				a[tmp1] = tmp2;
				break;
			case 'S':
				cin >> tmp1 >> tmp2;
				cout << tree.rangeSum(tmp1, tmp2) << endl;
				break;
			case 'Q':
				cin >> tmp1;
				cout << tree.numFreq(tmp1) << endl;
				break;
		}
	}
}
