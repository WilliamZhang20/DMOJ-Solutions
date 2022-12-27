#include <stdio.h>
#include <math.h>
// CCC 2003 J2

int main(void) {
  int k=0, c;
  int a[65000];
  while(1) {
    scanf("%d", &c);
    a[k]=c;
    if(c==0) {
      break;
    }
    k++;
  }
  for(int j=0; j<k; j++) {
    for(int i=sqrt(a[j]); i>0; i--) {
      if(a[j] % i==0) {
        printf("Minimum perimeter is %d with dimensions %d x %d\n", 2*i+2*(a[j]/i), i, a[j]/i);
        break;
      }
    }
  }
  return 0;
}
