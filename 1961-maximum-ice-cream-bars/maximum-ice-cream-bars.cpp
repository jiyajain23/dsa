class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        int i = 0;
        while (i<costs.size() && coins >= 0) {
            if (costs[i] <= coins) {
                ans++;
                coins -= costs[i];
            } else
                break;
            i++;
        }
        return ans;
    }
};