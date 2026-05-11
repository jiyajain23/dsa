class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> temp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            while (num >= 1) {
                int n = num % 10;
                num = num / 10;
                temp.push(n);
            }
        }
        while (!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};