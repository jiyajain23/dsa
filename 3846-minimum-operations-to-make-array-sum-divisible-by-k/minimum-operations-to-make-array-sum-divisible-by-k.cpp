class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=accumulate(nums.begin(),nums.end(),0);
        return x%k;
    }
};