#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
   int n = prices.size();
   int b = prices[0];int s = prices[0];
   int mx = INT_MIN;
   for(int i=0;i<n;i++){
       if(b>prices[i] && i!=n-1){
           b = prices[i];
           s = prices[i];
       }
       if(s<prices[i]){
           s = prices[i];
       }
       mx = max(s-b,mx);
   }
   return mx;
}