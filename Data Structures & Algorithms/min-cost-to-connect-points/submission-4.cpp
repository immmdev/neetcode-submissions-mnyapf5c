class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int dis=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dis});
            }
        }
        // dis,node
        int mst=0;
        vector<int>vis(n,0);
        pq.push({0,0});
        
        while(!pq.empty()){
            auto node=pq.top();
            int p=node.second;
            int c=node.first;
            pq.pop();
            if(vis[p]) continue;
            mst+=c;
            vis[p]=1;
        
            for(auto it:adj[p]){
                int next=it.first;
                int cost=it.second;
                if(!vis[next])pq.push({cost,next});
            }
        }
        return mst;
    }
};
