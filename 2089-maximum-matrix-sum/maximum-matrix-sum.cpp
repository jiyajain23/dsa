class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absSum = 0;
        int neg = 0, mini = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int n=matrix[i][j];
                mini = min(mini,abs(n));
                if (n < 0) {
                    neg++;
                }
                absSum += abs(n);
            }
        }
        if (neg % 2 == 1) absSum -= 2*mini;
        return absSum;
    }
};