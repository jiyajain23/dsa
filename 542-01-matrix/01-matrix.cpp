class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int add=0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if (x - 1 >= 0 && !vis[x - 1][y]) {
                    q.push({x - 1, y});
                    vis[x - 1][y] = 1;
                    mat[x - 1][y] += add;
                }
                if (y - 1 >= 0 && !vis[x][y - 1]) {
                    q.push({x, y - 1});
                    vis[x][y - 1] = 1;
                    mat[x][y - 1] += add;
                }
                if (x + 1 < m && !vis[x + 1][y]) {
                    q.push({x + 1, y});
                    vis[x + 1][y] = 1;
                    mat[x + 1][y] += add;
                }
                if (y + 1 < n && !vis[x][y + 1]) {
                    q.push({x, y + 1});
                    vis[x][y + 1] = 1;
                    mat[x][y + 1] += add;
                }
            }
            add++;
        }
        return mat;
    }
};