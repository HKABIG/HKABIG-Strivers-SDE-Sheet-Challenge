int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i] = max(dp[i],dp[i-j-1]+price[j]);
		}
	}
	return dp[n];
}
