class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> src = {0, 0};
        pair<int, int> des = {n - 1, n - 1};
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return 1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, src});
        int delrow[8] = {+1, -1, 0, -1, +1, +1, 0, -1};
        int delcol[8] = {+1, +1, +1, 0, 0, -1, -1, -1};
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int d = temp.first;
            auto [row, col] = temp.second;
            for (int i = 0; i < 8; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && d + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = d + 1;
                    if (nrow == des.first && ncol == des.second)
                        return d + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};