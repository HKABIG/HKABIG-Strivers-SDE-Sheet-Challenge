#include <bits/stdc++.h> 
    int solve(vector<int>& prices,int ind,int buy,int cap){
        // O(2^N)
        if(cap==0 || ind==prices.size()) return 0;
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+solve(prices,ind+1,0,cap),0+solve(prices,ind+1,1,cap));
        }
        else{
            profit = max(prices[ind]+solve(prices,ind+1,1,cap-1),0+solve(prices,ind+1,0,cap));
        }
        return profit;
    }
    int solveMem(vector<int>& prices,int ind,int buy,int cap,vector<vector<vector<int>>>& dp){
        // O(N^2)
        if(cap==0 || ind==prices.size()) return 0;
        int profit = 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            profit = max(-prices[ind]+solve(prices,ind+1,0,cap),0+solve(prices,ind+1,1,cap));
        }
        else{
            profit = max(prices[ind]+solve(prices,ind+1,1,cap-1),0+solve(prices,ind+1,0,cap));
        }
        return dp[ind][buy][cap]=profit;
    }
    int solveTab(vector<int>& prices){
        // O(N*2*3)
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }

    int solveTabImp(vector<int>& prices){
        // Space Optimized tabulation
        int n = prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap] = max(-prices[ind]+prev[0][cap],0+prev[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[ind]+prev[1][cap-1],0+prev[0][cap]);
                    }
                }
            }
            prev = curr;
        }
        return prev[1][2];
    }
    int solveSpaceTab(vector<int>& prices){
        int n = prices.size();
        int cap = 2;
        vector<vector<int>> dp(n+1,vector<int>(2*cap+1));
        for(int ind=n-1;ind>=0;ind--){
            for(int tranNo=2*cap-1;tranNo>=0;tranNo--){
                if(tranNo%2==0){
                    dp[ind][tranNo] = max(-prices[ind]+dp[ind+1][tranNo+1],0+dp[ind+1][tranNo]);
                }
                else{
                    dp[ind][tranNo] = max(prices[ind]+dp[ind+1][tranNo+1],0+dp[ind+1][tranNo]);
                }
            }
        }
        return dp[0][0];
    }
int maxProfit(vector<int>& prices, int n)
{
    // return solve(prices,0,1,2);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveMem(prices,0,1,2,dp);
        // return solveTab(prices);
        // return solveTabImp(prices);
        return solveSpaceTab(prices);
}