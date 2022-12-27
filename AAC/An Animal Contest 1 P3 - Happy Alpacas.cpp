#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int n, x, t, a[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    if((n - x) % 2){
        cout<<-1<<endl;
        return 0;
    }
    t = (n - x) / 2;
    for(int i = 0; i < n && t > 0; i++){
        if(!i || !a[i-1]){a[i] = 1; t--;}
    }
    if(t > 0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++) cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
}
