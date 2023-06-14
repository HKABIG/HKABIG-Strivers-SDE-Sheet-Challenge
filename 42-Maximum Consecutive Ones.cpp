#include <bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    int mxcnt = 0;
    int z = 0;
    int j = 0;int i = 0;
    while(j<n){
        if(arr[j]==0) z++;
        while(z>k){
            if(arr[i]==0) z--;
            i++;
        }
        mxcnt = max(mxcnt,j-i+1);
        j++;
    }
    return mxcnt;
}
