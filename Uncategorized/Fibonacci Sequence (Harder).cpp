#include <iostream>
#include <vector>
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define PB push_back
#define F first
#define S second
using namespace std;
const int mod=1e9+7;
ll mmod(string n){
	ll res=0;
	for (int i=0; i<n.length(); i++){
		res=(res*10+(int)(n[i]-'0'));
		res%=2000000016;
			//using pisano period to reduce large inputs to smaller problems
	}
	return res;
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b){
	vector<vector<ll>> res={{0,0}, {0,0}};
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			for (int h=0; h<2; h++){
				res[i][j]+=a[i][h]*b[h][j];
				res[i][j]%=mod;
			}
		}
	}
	return res;
}
int main() {
cin.tie(0); cin.sync_with_stdio(0);
	vector<vector<ll>> b={{1,0}, {0,1}};
	vector<vector<ll>> m={{1,1}, {1,0}};
	string num;
		cin>>num;
		ll n=mmod(num);
		while (n>0){
			if (n%2){
				b=mul(b, m);
			}
			m=mul(m, m);
			n/=2;
		}
	cout<<b[0][1]<<endl;
  return 0;
}
