#include <bits/stdc++.h>
long help(int ind,int buy,long* values,int n){
    if(ind==n) return 0;
    long profit = 0;
    if(buy){
        profit = max(-values[ind] + help(ind+1,0,values,n),0 + help(ind+1,1,values,n));
    }
    else{
        profit = max(values[ind] + help(ind+1,1,values,n),0 + help(ind+1,0,values,n));   
    }
    return profit;
}

long helpMem(int ind,int buy,long* values,int n,vector<vector<long>> &dp){
    if(ind==n) return 0;
    long profit = 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy){
        profit = max(-values[ind] + help(ind+1,0,values,n),0 + help(ind+1,1,values,n));
    }
    else{
        profit = max(values[ind] + help(ind+1,1,values,n),0 + help(ind+1,0,values,n));   
    }
    return dp[ind][buy]=profit;
}

long helpTab(int ind,int buy,long* values,int n){
    vector<vector<long>> dp(n+1,vector<long>(2,-1));// At a index I will either buy or sell
    dp[n][0] = dp[n][1] = 0;
    long profit = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        if(buy){
            dp[ind][buy] = max(-values[ind] + dp[ind+1][0],0 + dp[ind+1][1]);
        }
        else{
            dp[ind][buy] = max(values[ind] + dp[ind+1][1],0 + dp[ind+1][0]);   
        }
        }
    }
    return dp[0][1];
}

long helpTabImp(int ind,int buy,long* values,int n){
    vector<long> prev(2,0),cur(2,0);
    prev[0]=prev[1]=0;
    long profit = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        if(buy){
            profit = max(-values[ind] + prev[0],0 + prev[1]);
        }
        else{
            profit = max(values[ind] + prev[1],0 + prev   [0]);   
        }
        cur[buy] = profit;
        }
        prev = cur;

    }
    return prev[1];
}

int solveTab(long* prices,int n){
        long aheadBuy,aheadNotBuy;
        aheadBuy = aheadNotBuy = 0;
        long curBuy,curNotBuy;
        for(int ind=n-1;ind>=0;ind--){
            curBuy = max(-prices[ind] + aheadNotBuy,0 + aheadBuy);
            curNotBuy = max(prices[ind]+aheadBuy,0+aheadNotBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;

    }

long getMaximumProfit(long *values, int n){
    // return help(0,1,values,n);
    vector<vector<long>> dp(n,vector<long>(2,-1));// At a index I will either buy or sell
    // return helpMem(0,1,values,n,dp);
    // return helpTab(0,1,values,n);
    // return helpTabImp(0,1,values,n);
    return solveTab(values,n);
}