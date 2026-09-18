class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        int fresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                } else if (grid[i][j]==1) {
                    fresh++;
                }
            }

        }
        int mtime=0;
        while(!q.empty()){
            auto node=q.front();
            int t=node.first;
            int row=node.second.first;
            int col=node.second.second;
            q.pop();
            mtime=max(mtime,t);
            int r[4]={-1,1,0,0};
            int c[4]={0,0,1,-1};
            for(int k=0; k<4; k++){
                int nr=r[k]+row;
                int nc=c[k]+col;
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]!=1 && grid[nr][nc]==1){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=1;
                    fresh--;
                }
            }
        }
        return fresh==0? mtime : -1;
    }
};
