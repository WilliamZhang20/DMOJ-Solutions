#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

const ull MOD = 1e9+7;

struct Matrix {
	ull a[2][2];
	Matrix operator*(Matrix mt) {
		Matrix product{{{0, 0}, {0, 0}}};
		for(int i=0; i<2; i++) {
			for(int j=0; j<2; j++) {
				for(int k=0; k<2; k++) {
					a[i][j] %= MOD;
					mt.a[j][k] %= MOD;
					product.a[i][k] += a[i][j] * mt.a[j][k];
					product.a[i][k] %= MOD;
				}
			}
		}
		return product;
	}
};

Matrix power(Matrix mt, ull num) {
	Matrix res{{{1, 0}, {0, 1}}};
	while(num>0) {
		if(num%2!=0) {
			res = res * mt;
		}
		num /= 2;
		mt = mt * mt;
	}
	return res;
}

int solve_fib(ull n) {
	Matrix mt {{{0, 1}, {1, 1}}};
	if(n==0) {
		return 0;
	}
	if(n==1 || n==2) {
		return 1;
	} 
	mt = power(mt, n-1);
	return mt.a[0][0] + mt.a[0][1];
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	ull n;
	cin >> n;
	cout << solve_fib(n) % MOD << "\n";
	return 0;
}
