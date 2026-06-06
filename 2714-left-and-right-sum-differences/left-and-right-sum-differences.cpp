class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        for(int i=0;i<n;i++){
            if(i==0) {
                leftSum[i]=0;
                rightSum[n-1-i]=0;
                continue;
            }
            leftSum[i]=nums[i-1]+leftSum[i-1];
            rightSum[n-i-1]=nums[n-i]+rightSum[n-i];
        }
        for(int i=0;i<n;i++){
            leftSum[i]=abs(leftSum[i]-rightSum[i]);
        }
        return leftSum;
    }
};