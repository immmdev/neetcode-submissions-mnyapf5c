class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int i,int j,int n,int m){
        vis[i][j]=1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0; k<4; k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && board[nrow][ncol]!='X' && vis[nrow][ncol]!=1)
            dfs(board,vis,nrow,ncol,n,m);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++){
            if(board[0][i]=='O' && vis[0][i]!=1){
                dfs(board,vis,0,i,n,m);
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && vis[i][0]!=1){
                dfs(board,vis,i,0,n,m);
            }
        }

        for(int i=0; i<m; i++){
            if(board[n-1][i]=='O' && vis[n-1][i]!=1){
                dfs(board,vis,n-1,i,n,m);
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O' && vis[i][m-1]!=1){
                dfs(board,vis,i,m-1,n,m);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};
