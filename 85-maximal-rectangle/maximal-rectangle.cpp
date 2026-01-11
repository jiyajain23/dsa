class Solution {
public:
    vector<vector<int>> preSum(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == '1')
                    pre += 1;
                else
                    pre = 0;
                ans[j][i] = pre;
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int nse = n, pse = -1, elem = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                elem = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(heights[elem] * (nse - pse - 1), maxi);
            }
            st.push(i);
        }
        while (!st.empty()) {
            nse = n;
            elem = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxi = max(heights[elem] * (nse - pse - 1), maxi);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        vector<vector<int>> preCom = preSum(matrix);
        int maxi = 0;
        for (int i = 0; i < matrix.size(); i++) {
            maxi = max(maxi, largestRectangleArea(preCom[i]));
        }
        return maxi;
    }
};