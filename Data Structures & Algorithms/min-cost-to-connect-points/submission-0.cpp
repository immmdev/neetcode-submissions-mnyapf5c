

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dist,j});
            }
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        // vis[0]=1;
        int mst=0;
        while(!pq.empty()){
            auto node=pq.top();
            int c=node.first;
            int p=node.second;
            pq.pop();
            if(vis[p]==1)continue;
            mst+=c;
            vis[p]=1;
            for(auto it:adj[p]){
                int n=it.second;
                int cost=it.first;
                if(!vis[n]) pq.push({cost,n});
            }        
        }
        return mst;
    }
};
