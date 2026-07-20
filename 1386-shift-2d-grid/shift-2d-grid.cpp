class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> flat(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flat[i * n + j] = grid[i][j];
            }
        }
        k = k % (m * n);
        reverse(flat.begin(), flat.end()  - k);
        reverse(flat.end() - k , flat.end());
        reverse(flat.begin(), flat.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = flat[i * n + j];
            }
        }
        return grid;
    }
};