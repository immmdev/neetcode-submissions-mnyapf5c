class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int i=0; i<4; i++){
            int nrow=dr[i]+row;
            int ncol=dc[i]+col;
            if(ncol>=0 && nrow>=0 && ncol<m && nrow<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(grid,nrow,ncol,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j,vis);
                }
            }
        }

        return cnt;

    }
};
