class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int ans = -1;
        int minReachable = INT_MAX;
        vector<int> cityNums(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.push({0, i});
            while (!q.empty()) {
                auto [d, node] = q.top();
                q.pop();
                if (d > dist[node])
                    continue;
                for (auto neigh : adj[node]) {
                    int v = neigh.first;
                    int w = neigh.second;
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        q.push({dist[v], v});
                    }
                }
            }
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold)
                    count++;
            }

            if (count <= minReachable) {
                minReachable = count;
                ans = i;
            }
        }

        return ans;
    }
};