class Solution {
public:
    void dfs(int k, vector<int>& vis, vector<vector<int>> &adj) {
        vis[k] = 1;
        for (int a : adj[k]) {
            if (!vis[a]) {
                dfs(a, vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> vis(n, 0);
        dfs(k, vis, adj);

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;;
    }
};