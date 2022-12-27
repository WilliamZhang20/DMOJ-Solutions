#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {

  string city,cold_city;
  int temp,low_temp=INT_MAX;
  while (1) {
  
    cin>>city;
    scanf("%d",&temp);

    if (temp<low_temp) {
      low_temp=temp;
      cold_city=city;
    }

    if (city=="Waterloo") {
      break;
    }

  }

  cout<<cold_city<<endl;

  return 0;

}
