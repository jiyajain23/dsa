class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        const int mod = 1e9 + 7;
        priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<>> pq;
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node])
                continue;

            for (auto nei : adj[node]) {
                int v = nei.first;
                long long dis = (long long)d + nei.second;
                if (dis < dist[v]) {
                    ways[v] = ways[node];
                    dist[v] = dis;
                    pq.push({dis, v});
                } else if (dis == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};