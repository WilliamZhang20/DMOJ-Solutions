#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// 2spooky4me
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll N, L, S;
  ll temp;
  ll a, b, spook;
  ll currLvl=0;
  vector<pair<ll, ll>> track;
  ll amount;
  cin >> N >> L >> S;
  amount = L;
  while(N--) {
    cin >> a >> b >> spook;
    track.push_back({a, spook});
    track.push_back({b+1, -1*spook});
  }
  sort(track.begin(), track.end());
  for(ll i=0; i<track.size(); i++) {
    if(track[i].first==track[i+1].first) {
      if(track[i].second<track[i+1].second) {
        temp = track[i].second;
        track[i].second = track[i+1].second;
        track[i+1].second = temp;
      }
    }
    currLvl+=track[i].second;
    if(currLvl>=S) {
      amount-=track[i+1].first-track[i].first;
    }
  }
  cout << amount << endl;
}
