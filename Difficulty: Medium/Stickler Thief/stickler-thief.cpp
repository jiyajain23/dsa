class Solution {
  public:
    int func(int ind,vector<int>& arr, int n,vector<int> &dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+func(ind+2,arr,n,dp);
        int notPick=0+func(ind+1,arr,n,dp);
        
        return dp[ind]=max(pick,notPick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return func(0,arr,n,dp);
    }
};