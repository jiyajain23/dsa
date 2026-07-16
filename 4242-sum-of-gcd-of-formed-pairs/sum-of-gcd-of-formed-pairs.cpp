class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int premx = INT_MIN;
        vector<int> mx(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > premx) {
                premx = nums[i];
            }
            mx[i] = premx;
        }
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            prefixGcd[i] = gcd(mx[i], nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end(), greater<>());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }
        return ans;
    }
};