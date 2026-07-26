class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int n=nums.size();
        int ans=max(nums[0]*nums[1]*nums[2],nums[n-1]*nums[n-2]*nums[0]);
        return ans;
    }
};