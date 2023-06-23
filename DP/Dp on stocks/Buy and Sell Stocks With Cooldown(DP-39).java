class Solution {
    int solve(int ind,int buy,int[] prices){
        if(ind>=prices.length) return 0;
        int price = 0;
        if(buy==1){
            price = Math.max(-prices[ind]+solve(ind+1,0,prices),0+solve(ind+1,1,prices));
        }
        else{
            price = Math.max(prices[ind]+solve(ind+2,1,prices),0+solve(ind+1,0,prices));
        }
        return price;
    }
    int solveMem(int ind,int buy,int[] prices,int[][] dp){
        if(ind>=prices.length) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int price = 0;
        if(buy==1){
            price = Math.max(-prices[ind]+solveMem(ind+1,0,prices,dp),0+solveMem(ind+1,1,prices,dp));
        }
        else{
            price = Math.max(prices[ind]+solveMem(ind+2,1,prices,dp),0+solveMem(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = price;
    }
    int solveTab(int[] prices){
        int n = prices.length;
        int[][] dp = new int[n+2][2];
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[ind][buy] = Math.max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = Math.max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
    int solveTabImp(int[] prices){
        // TC:O(N) SC:O(N^2)
        int n = prices.length;
        int[][] dp = new int[n+2][2];
        for(int ind=n-1;ind>=0;ind--){
            dp[ind][1] = Math.max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            dp[ind][0] = Math.max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
        }
        return dp[0][1];
    }
    int solveSpace(int[] prices){
        // TC:O(N) SC:O(1)
        int n = prices.length;
        int[] front1 = new int[2];
        int[] front2 = new int[2];
        int[] curr = new int[2];
        for(int ind=n-1;ind>=0;ind--){
            curr[1] = Math.max(-prices[ind]+front1[0],0+front1[1]);
            curr[0] = Math.max(prices[ind]+front2[1],0+front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
    public int maxProfit(int[] prices) {
        // return solve(0,1,prices);
        // int n = prices.length;
        // int[][] dp = new int[n+1][2];
        // for(int i=0;i<=n;i++){
        //     Arrays.fill(dp[i],-1);
        // }
        // return solveMem(0,1,prices,dp);
        // return solveTab(prices);
        // return solveTabImp(prices);
        return solveSpace(prices);
    }
}