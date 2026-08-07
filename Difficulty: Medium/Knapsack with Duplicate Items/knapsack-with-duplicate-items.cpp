class Solution {
	public:
	int maxCap(int i, vector<int>& val, vector<int>& wt,int capacity,vector<vector<int>> &dp, int currCap) {
		if (i>wt.size() - 1)
			return 0;
		if (currCap > capacity) return INT_MIN;
		if (dp[i][currCap] != -1)
			return dp[i][currCap];
		
	    int	take = val[i] + maxCap(i, val, wt, capacity, dp, currCap + wt[i]);
		int notTake = maxCap(i+1, val, wt, capacity,dp,currCap);
		
		return dp[i][currCap] = max(take, notTake);;
		
	}
	int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
		// code here
		int n = wt.size();
		vector<vector<int>>dp(n, vector<int>(capacity + 1, -1));
		
		return maxCap(0,val,wt,capacity,dp,0);
		
	}
};
