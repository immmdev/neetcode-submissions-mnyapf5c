class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dis(n,1e4);
        // stop,node,price
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty()){
            auto el=q.front();
            int stops=el.first;
            int node=el.second.first;
            int cost=el.second.second;
            q.pop();
            if(stops>k)continue;
            for(auto it:adj[node]){
                int next=it.first;
                int wt=it.second;
                if(wt+cost<dis[next]){
                    dis[next]=wt+cost;
                    q.push({stops+1,{next,dis[next]}});
                }
            }
        }
        if(dis[dst]==1e4)return -1;
        return dis[dst];
    }
};
