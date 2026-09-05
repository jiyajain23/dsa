class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int postFix[n];
        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < currMin)
                currMin = nums[i];
            postFix[i] = currMin;
        }
        int currMax = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > currMax)
                currMax = nums[i];
            if (currMax - postFix[i] <= k)
                return i;
        }
        return -1;
    }
};