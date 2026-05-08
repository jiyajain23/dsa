// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            dist[u][v]=d;
            dist[v][u]=d;
        }
        
        int cntCity=n,cityNo=-1;
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e9 || dist[k][j]==1e9) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntCity){
                cntCity=cnt;
                cityNo=i;
            }
        }
        return cityNo;
    }
};
