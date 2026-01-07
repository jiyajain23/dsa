class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(i==0 || i==m-1){
                for(int j=0;j<n;j++){
                     if(board[i][j]=='O') {
                        q.push({i,j});
                        vis[i][j]=1;
                     }
                }
            }
            else{
                if(board[i][0]=='O'){
                    q.push({i,0});
                    vis[i][0]=1;
                }if(board[i][n-1]=='O'){
                    q.push({i,n-1});
                    vis[i][n-1]=1;
                }
            }  
        }

        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(int i=0;i<4;i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};