class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<double> dist(n, 1e18);
        dist[start_node] = 0.0;

        for (int i = 0; i < n - 1; i++) {
            bool updated = false;

            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double w = -log(succProb[j]);

                if (dist[u] != 1e18 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }

                if (dist[v] != 1e18 && dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    updated = true;
                }
            }

            if (!updated)
                break;
        }

        if (dist[end_node] == 1e18)
            return 0.0;
        return exp(-dist[end_node]);
    }
};