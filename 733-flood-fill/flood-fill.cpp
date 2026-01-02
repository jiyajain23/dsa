class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int ogc = image[sr][sc];
        if(ogc==color) return image;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int m = image.size();
        int n = image[0].size();
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if (x - 1 >= 0 && image[x - 1][y] == ogc) {
                    image[x - 1][y] = color;
                    q.push({x - 1, y});
                }
                if (x + 1 < m && image[x + 1][y] == ogc) {
                    image[x + 1][y] = color;
                    q.push({x + 1, y});
                }
                if (y - 1 >= 0 && image[x][y - 1] == ogc) {
                    image[x][y - 1] = color;
                    q.push({x, y - 1});
                }
                if (y + 1 < n && image[x][y + 1] == ogc) {
                    image[x][y + 1] = color;
                    q.push({x, y + 1});
                }
            }
        }
        return image;
    }
};