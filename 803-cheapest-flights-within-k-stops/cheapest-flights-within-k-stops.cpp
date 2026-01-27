class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        while (!q.empty()) {
            auto [st, s] = q.front();
            auto [d, node] = s;
            q.pop();
            if (st > k) continue;
            for (auto it : adj[node]) {
                int nei = it.first;
                int w = it.second;
                if (w + d < dist[nei] && st <= k) {
                    dist[nei] = w + d;
                    q.push({st + 1, {dist[nei], nei}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};