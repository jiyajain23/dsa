class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //adjacency 
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
         priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(V,1e9);
        dist[src]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            int n=temp.second;
            int d=temp.first;
            pq.pop();
            if (d > dist[n]) continue;
            for(auto nei:adj[n]){
                int ne=nei.first;
                int w=nei.second;
                if(d+w<dist[ne]){
                    dist[ne]=d+w;
                    pq.push({dist[ne],ne});
                }
            }
        }
        return dist;
    }
};