class Solution {
  public:
  
    void dfs(int v,vector<vector<int>> &adj,vector<int> &vis,
        stack<int> &st){
            vis[v]=1;
            for(int nei:adj[v]){
                if(!vis[nei]){
                    dfs(nei,adj,vis,st);
                }
            }
            st.push(v);
        }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        int j=0;
        while(!st.empty()){
            vis[j]=st.top();
            st.pop();
            j++;
        }
        return vis;
    }
};