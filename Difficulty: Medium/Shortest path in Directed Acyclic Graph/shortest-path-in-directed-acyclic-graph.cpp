// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> dist(V,-1);
        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                int node=it.first;
                int dista=it.second+dist[temp];
                if(dist[node]==-1 || dista<dist[node]){
                    dist[node]=dista;
                    q.push(node);
                }
            }
        }
        return dist;
    }
};
