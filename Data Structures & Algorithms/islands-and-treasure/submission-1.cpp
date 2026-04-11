class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }

            }
        }
        int INF=2147483647;
        while(!q.empty()){
            auto node=q.top();
            int dis=node.first;
            int row=node.second.first;
            int col=node.second.second;
            q.pop();
            int dr[4]={1,-1,0,0};
            int dc[4]={0,0,1,-1};
            for(int k=0; k<4; k++){
                int nrow=dr[k]+row;
                int ncol=dc[k]+col;
                if(nrow<n && ncol<m&& nrow>=0 && ncol>=0 && vis[nrow][ncol]!=1 && grid[nrow][ncol]!=-1 && grid[nrow][ncol]!=0){
                    q.push({dis+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=dis+1;
                }
            }
        }
    }
};
