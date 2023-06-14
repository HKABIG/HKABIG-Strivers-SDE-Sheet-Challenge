#include <bits/stdc++.h> 
#define ll long
long getTrappedWater(long *arr, int n){
    vector<ll> left(n,0);
    vector<ll> right(n,0);
    ll leftmax = arr[0];
    ll rightmax = arr[n-1];
    ll trap = 0;
    for(int i=1;i<n;i++){
        leftmax = max(leftmax,arr[i]);
        left[i] = leftmax;
    }
    for(int i=n-2;i>=0;i--){
        rightmax = max(rightmax,arr[i]);
        right[i] = rightmax;
    }
    for(int i=1;i<n-1;i++){
        trap += abs(arr[i]-min(left[i],right[i]));
    }
    return trap;
}