class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        if (vis[node] == 1) return true;  
        if (vis[node] == 2) return false;  
        vis[node] = 1; 
        for (int nei : graph[node]) {
            if (dfs(nei, graph, vis))
                return true;
        }
        vis[node] = 2; 
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!dfs(i, graph, vis))
                ans.push_back(i);
        }
        return ans;
    }
};
