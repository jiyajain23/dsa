class Solution {
  public:
    int func(int n,int c,vector<int> &dp){
        if(c==n) return 1;
        if(c>n) return 0;
        if(dp[c]!=-1) return dp[c];
        dp[c+1]=func(n,c+1,dp);
        dp[c+2]=func(n,c+2,dp);
        
        return dp[c]=dp[c+1]+dp[c+2];
    }
    int countWays(int n) {
        // code here
        vector<int> dp(n+2,-1);
        return func(n,0,dp);
    }
};
