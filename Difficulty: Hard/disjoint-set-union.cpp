#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
  vector<int> rank,par;
public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    par.resize(n+1);
    for (int i = 0; i <= n; i++) {
            parent[i] = i;
    }
  }
  int findUpar(int node){
    if(node==par[node]) return node;
    return par[node]=findUpar(node);
  }
  void unionByRank(int u,int v){
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(rank[ulp_u]<rank[ulp_v]){
      par[ulp_u]=ulp_v;
    }else if(rank[ulp_v]<rank[ulp_u]){
      par[ulp_v]=ulp_u;
    }else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
