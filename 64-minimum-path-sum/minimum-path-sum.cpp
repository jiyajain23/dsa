class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int left=INT_MAX,up=INT_MAX;
                if(i>0) left=dp[i-1][j];
                if(j>0) up=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(left,up);
            }
        }
        return dp[n-1][m-1];
    }
};