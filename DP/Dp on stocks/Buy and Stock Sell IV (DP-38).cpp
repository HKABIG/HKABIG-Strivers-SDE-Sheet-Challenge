class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,int cap){
        if(cap==0 || ind==prices.size()) return 0;
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+solve(ind+1,0,prices,cap),0+solve(ind+1,1,prices,cap));
        }
        else{
            profit = max(prices[ind]+solve(ind+1,1,prices,cap-1),0+solve(ind+1,0,prices,cap));
        }
        return profit;
    }
    int solveMem(int ind,int buy,vector<int>& prices,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0 || ind==prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+solveMem(ind+1,0,prices,cap,dp),0+solveMem(ind+1,1,prices,cap,dp));
        }
        else{
            profit = max(prices[ind]+solveMem(ind+1,1,prices,cap-1,dp),0+solveMem(ind+1,0,prices,cap,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int solveTab(vector<int>& prices,int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                if(buy){
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                }
                }
            }
        }
        return dp[0][1][k];
    }
    int solveTabImp(vector<int>& prices,int k){
        int n = prices.size();
        vector<vector<int>> prev(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return prev[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(0,1,prices,k);
        // return solveMem(0,1,prices,k,dp);// There is a overflow in this
        // return solveTab(prices,k);
        return solveTabImp(prices,k);
    }
};