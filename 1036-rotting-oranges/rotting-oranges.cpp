class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int count1=0,count0=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j]==1) count1++;
                if(grid[i][j]==0) count0++;
            }
        }
        if(q.empty() && count1>0) return -1;
        if(q.empty() && count0>0 && count1==0) return 0;
        int minutes = -1;
        while (!q.empty()) {
            minutes++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    count1--;
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    count1--;
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    count1--;
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    count1--;
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }
        }
        if(count1>0) return -1;
        return minutes;
    }
};