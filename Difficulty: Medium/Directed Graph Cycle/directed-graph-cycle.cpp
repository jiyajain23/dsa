class Solution {
  public:
  
    bool dfs(int v, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
        pathVis[v]=vis[v]=1;
        for(auto nei:adj[v]){
            if(!vis[nei]){
                 if(dfs(nei,vis,pathVis,adj)) return true;
            }else if (pathVis[nei]) {
				return true;
			}

        }
        pathVis[v]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // adjacency list
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0),pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)) return true;
            }
        }
        return false;
    }
};