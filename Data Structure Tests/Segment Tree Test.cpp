#include <bits/stdc++.h>
#define int long long
#define MAX 100001
using namespace std;
// Segment Tree Test

vector<int> minST(MAX*4); // min values
vector<int> arr(MAX); // original array
pair<int, int> gcdST[MAX*4]; // gcd, frequency
int n, m;

void pushMin(int i) {
	minST[i] = min(minST[i*2], minST[i*2+1]);
}

void buildMin(int i, int l, int r) {
	if(l==r) {
		minST[i] = arr[l];
		return;
	} 
	int mid = (l+r)/2;
	buildMin(i*2, l, mid);
	buildMin(i*2+1, mid+1, r);
	pushMin(i);
}

void updateMin(int i, int l, int r, int pos, int val) {
	if(l==r) {
		minST[i] = val;
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid) updateMin(i*2, l, mid, pos, val);
	else updateMin(i*2+1, mid+1, r, pos, val);
	pushMin(i);
}

int rmq(int i, int l, int r, int lo, int hi) {
	if(lo>hi) {
		return 1e9+1;
	}
	if(l==lo && r==hi) {
		return minST[i];
	}
	int mid = (l+r)/2;
	return min(rmq(i*2, l, mid, lo, min(hi, mid)), rmq(i*2+1, mid+1, r, max(lo, mid+1), hi));
}

pair<int, int> combineGcd(pair<int, int> a, pair<int, int> b) {
	int val, freq=0;
	val = __gcd(a.first, b.first);
	freq += (a.first==val) * a.second;
	freq += (b.first==val) * b.second;
	return make_pair(val, freq);
}

void buildGcd(int i, int l, int r) {
	if(l==r) {
		gcdST[i] = make_pair(arr[l], 1);
		return;
	}
	int mid = (l+r)/2;
	buildGcd(i*2, l, mid);
	buildGcd(i*2+1, mid+1, r);
	gcdST[i] = combineGcd(gcdST[i*2], gcdST[i*2+1]);
}

void updateGcd(int i, int l, int r, int pos, int val) {
	if(l==r) {
		gcdST[i] = make_pair(val, 1);
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid) {
		updateGcd(i*2, l, mid, pos, val);
	} else {
		updateGcd(i*2+1, mid+1, r, pos, val);
	}
	gcdST[i] = combineGcd(gcdST[i*2], gcdST[i*2+1]);
}

pair<int, int> findGcd(int i, int l, int r, int lo, int hi) {
	if(l>hi || r<lo) {
		return make_pair(0, 0);
	}
	if(lo<=l && hi>=r) {
		return gcdST[i];
	}
	int mid = (l+r)/2;
	return combineGcd(findGcd(i*2, l, mid, lo, min(hi, mid)), findGcd(i*2+1, mid+1, r, max(lo, mid+1), hi));
}

int32_t main(void) { // int is now long long with the macro, so to set back to 32-bit integer, use int32_t
	ios_base::sync_with_stdio(0), cin.tie(0);
	char ch;
	cin >> n >> m;
	arr[0] = -1;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	buildGcd(1, 1, n);
	buildMin(1, 1, n);
	while(m--) {
		cin >> ch;
		if(ch=='C') {
			int x, v;
			cin >> x >> v;
      		updateGcd(1, 1, n, x, v);
			updateMin(1, 1, n, x, v);
		} 
		else if(ch=='M') {	
			int l, r;
			cin >> l >> r;
			cout << rmq(1, 1, n, l, r) << endl;
		} 
		else if(ch=='G') {
			int l, r;
			cin >> l >> r;
			pair<int, int> t = findGcd(1, 1, n, l, r);
			cout << t.first << endl;
		} 
		else if(ch=='Q') {
			int l, r;
			cin >> l >> r;
			pair<int, int> t = findGcd(1, 1, n, l, r);
			cout << t.second << endl;
		}
	}
	return 0;
}
