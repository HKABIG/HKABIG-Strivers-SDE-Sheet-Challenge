#include <bits/stdc++.h>
const int N = 1e5+2,MOD = 1e9+7;
int modularExponentiation(int x, int n, int m) {
    int ans = 1;
    while(n>0){
        if(n&1){
            ans = (1LL*ans*x)%m;
        }
        x = (1LL*x*x)%m;
        n >>= 1;
    }
    return ans;
}