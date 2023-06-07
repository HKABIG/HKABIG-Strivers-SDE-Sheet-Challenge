#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
		int m = 0;
        int r = 0;
        sort(arr.begin(),arr.end());
        int sum = 0;
        int tsum = 0;
        for(int i=1;i<=n;i++){
            tsum += i;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                r = arr[i];
            }
        }
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        m = abs((sum-r)-tsum);
        return {m,r};
}
