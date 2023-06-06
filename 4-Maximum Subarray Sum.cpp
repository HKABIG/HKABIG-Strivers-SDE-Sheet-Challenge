#include <bits/stdc++.h> 
#define ll long long 
long long maxSubarraySum(int a[], int n)
{
    ll maxSum = 0;
    ll curSum = 0;
    for(int i=0;i<n;i++){
        curSum += a[i];
        if(curSum>maxSum){
            maxSum = curSum;
        }
        if(curSum<0){
            curSum = 0;
        }
    }
    return maxSum;
}