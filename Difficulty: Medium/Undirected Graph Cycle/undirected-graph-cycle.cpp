class Solution {
  public:
    
    bool dfs(int node, int par,vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        for(int nei:adj[node]){
            if(!vis[nei]){
                if(dfs(nei,node,vis,adj)) return true;
            }
            else if(nei!=par) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //build adjacency list;
        if(V==2 && edges.size()==1) return false;
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        // BFS
        // queue<pair<int,int>> q;
        // for(int i=0;i<V;i++){
        //     if (!vis[i]) {
        //     queue<pair<int,int>> q;
        //     q.push({i, -1});
        //     vis[i] = 1;

        //     while (!q.empty()) {
        //         auto [node, parent] = q.front();
        //         q.pop();

        //         for (int nei : adj[node]) {
        //             if (!vis[nei]) {
        //                 vis[nei] = 1;
        //                 q.push({nei, node});
        //             }
        //             else if (nei != parent) {
        //                 return true;  // cycle found
        //             }
        //         }
        //     }
        //  }
        //}
        
        //DFS
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};