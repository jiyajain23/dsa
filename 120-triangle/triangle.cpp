class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int same=1e8,next=1e8;
                if(dp[i+1][j+1]!=1e8) next=dp[i+1][j+1];
                if(dp[i+1][j]!=1e8) same=dp[i+1][j];
                dp[i][j]=triangle[i][j]+min(next,same);
            }
        }
        return dp[0][0];
    }
};