class Solution {
public:
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
        color[v] = c;
        for (auto it : graph[v]) {
            if (color[it] == c)
                return false;
            else {
                if (color[it] == -1) {
                    if (!dfs(it, graph, color, !c))
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!dfs(i, graph, color, 0))
                    return false;
            }
        }
        return true;
    }
};