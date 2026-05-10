class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num=accounts.size();
        DisjointSet ds(num);
        unordered_map<string,int> mpp;
        for(int i=0;i<num;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])!=mpp.end()){
                    ds.unionByRank(mpp[accounts[i][j]],i);
                }else mpp[accounts[i][j]]=i;
            }
        }
        vector<vector<string>> merged(num);
        for(auto it:mpp){
            string mail=it.first;
            int ulp=ds.findUPar(it.second);
            merged[ulp].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < num; i++) {
            if (merged[i].empty()) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &mail : merged[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};