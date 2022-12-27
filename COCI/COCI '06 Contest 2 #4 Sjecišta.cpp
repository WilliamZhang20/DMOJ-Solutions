#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n==3) {
        printf("0\n");
    } else {
        printf("%d\n", n*(n-1)*(n-2)*(n-3)/24);
    }
    return 0;
}
