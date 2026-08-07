class Solution {
public:
    int target(int i, int amount, vector<int>& coins,vector<vector<int>> &dp) {
        if (amount == 0)
            return 1;
        if (amount < 0)
            return 0;
        if (i == coins.size())
            return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTaken = target(i + 1, amount, coins,dp);
        int Taken = target(i, amount - coins[i], coins,dp);

        return dp[i][amount]=notTaken + Taken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+ 1,-1));
        return target(0, amount, coins,dp);
    }
};