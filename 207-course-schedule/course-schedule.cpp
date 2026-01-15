class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<inDeg.size();i++){
            if(inDeg[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            count++;
            for(int nei:adj[t]){
                inDeg[nei]--;
                if(inDeg[nei]==0) q.push(nei);
            }
        }
        return count==numCourses;
    }
};