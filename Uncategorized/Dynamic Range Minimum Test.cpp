#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
// Segment Tree Test

vector<int> minST(MAX*4); // min values
vector<int> arr(MAX); // original array
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

int main(void) { 
	ios_base::sync_with_stdio(0), cin.tie(0);
	char ch;
	cin >> n >> m;
	arr[0] = -1;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	buildMin(1, 1, n);
	while(m--) {
		cin >> ch;
		if(ch=='M') {
			int x, v;
			cin >> x >> v;
			updateMin(1, 1, n, x+1, v);
		} 
		else if(ch=='Q') {	
			int l, r;
			cin >> l >> r;
			cout << rmq(1, 1, n, l+1, r+1) << endl;
		} 
	}
	return 0;
}
