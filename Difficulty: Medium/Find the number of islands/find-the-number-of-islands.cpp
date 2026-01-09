class Solution {
  public:
    void bfs(int row,int col,vector<vector<char>>& grid, vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
         q.push({row,col});
         vis[row][col]=1;
         int delrow[8]={-1,0,+1,0,+1,-1,+1,-1};
         int delcol[8]={0,+1,0,-1,+1,+1,-1,-1};
         while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(int i=0;i<8;i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='L'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
         }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='L' && !vis[i][j]){
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};