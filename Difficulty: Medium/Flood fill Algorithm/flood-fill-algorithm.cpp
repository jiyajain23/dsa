class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        int startColor=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[sr][sc]=1;
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};
        
        while(!q.empty()){
            auto [crow,ccol]=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=crow+delrow[i];
                int ncol=ccol+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && image[nrow][ncol]==startColor){
                    image[nrow][ncol]=newColor;
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return image;
    }
};