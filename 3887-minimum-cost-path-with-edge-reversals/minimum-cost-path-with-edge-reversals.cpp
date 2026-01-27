class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        while(!pq.empty()){
            int node=pq.top().first;
            int d=pq.top().second;
            if(node==n-1) return d;
            pq.pop();
            for(auto it:adj[node]){
                int nei=it.first;
                int w=it.second;
                if(w+d<dist[nei]){
                    dist[nei]=w+d;
                    pq.push({nei,dist[nei]});
                }
            }
        }
        return -1;
        }
};