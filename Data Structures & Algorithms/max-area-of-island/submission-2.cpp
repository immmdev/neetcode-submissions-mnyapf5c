class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        int ar=1;
        int m=grid.size();
        int n=grid[0].size();
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int nr=i+r[k];
            int nc=j+c[k];
            if(nc>=0 && nr>=0 && nc<n && nr<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                ar+=dfs(nr,nc,grid,vis);
            }
        }

        return ar;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxar=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    maxar=max(dfs(i,j,grid,vis),maxar);
                }
            }
        }
        return maxar;
    }
};
