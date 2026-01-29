class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> time(n+1,1e9);
        time[0]=0;
        time[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0,k});
        while(!q.empty()){
            auto[t,no]=q.top();
            q.pop();
            for(auto nei:adj[no]){
                auto[v,w]=nei;
                if(t+w<time[v]){
                    time[v]=t+w;
                    q.push({time[v],v});
                }
            }
        }
        int ans = *max_element(time.begin(), time.end());
        return ans == 1e9? -1 : ans;
    }
};