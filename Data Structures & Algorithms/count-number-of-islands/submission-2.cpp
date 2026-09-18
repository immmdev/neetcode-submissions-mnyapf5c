class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int nr=i+r[k];
            int nc=j+c[k];
            if(nc>=0 && nr>=0 && nc<n && nr<m && grid[nr][nc]=='1' && vis[nr][nc]!=1){
                dfs(nr,nc,grid,vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
