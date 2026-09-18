class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto node=q.front();
            int row=node.second.first;
            int col=node.second.second;
            int dis=node.first;
            q.pop();
            int n=grid.size();
            int m=grid[0].size();
            int r[4]={-1,1,0,0};
            int c[4]={0,0,-1,1};
            for(int k=0; k<4; k++){
            int nr=r[k]+row;
            int nc=c[k]+col;
            // propgation of dis i all 4 directions posible so get the min dis in one attemp.
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] && vis[nr][nc]==0 && grid[nr][nc]!=-1){
                q.push({dis+1,{nr,nc}});
                vis[nr][nc]=1; 
                grid[nr][nc]=dis+1;
            }
            }
        }
    }
};
