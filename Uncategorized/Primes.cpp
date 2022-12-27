#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, count=1, x, i=2, j;
  bool isPrime;
  scanf("%d", &n);
  while(count <= n)
	{
		x = 0;
		for(j=2; j <= i/2; j++)
		{
			if(i%j==0)
			{
			  x=1;
			  break;
			}
		}
		if(x==0)
		{
			printf("%d\n", i);
			count++;
		}
		i++;
	}
}
