class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    vector<vector<int>> adj(V);
    for(auto &it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dist(V, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0; 
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbor : adj[node]) {
            if(dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    return dist;
}
};
