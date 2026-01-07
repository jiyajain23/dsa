class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1) {
            grid[row][col] = 0;
            dfs(row + 1, col, grid);
            dfs(row - 1, col, grid);
            dfs(row, col + 1, grid);
            dfs(row, col - 1, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, grid);
            }
            if (grid[m - 1][i] == 1) {
                dfs(m - 1, i, grid);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[j][0] == 1) {
                dfs(j, 0, grid);
            }
            if (grid[j][n - 1] == 1) {
                dfs(j, n - 1, grid);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};