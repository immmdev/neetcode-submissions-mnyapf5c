
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int inf=INT_MAX;
        vector<int>dis(n+1,inf);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {dist,node}
        pq.push({0,k});
        dis[k]=0;
        int minTime=-1;
        while(!pq.empty()){
            auto node=pq.top();
            int t=node.first;
            int u=node.second;
            pq.pop();
            for(auto it:adj[u]){
                int v=it.first;
                int time=it.second;
                
                if(dis[u]<dis[v] && dis[u]+time<dis[v]){
                    dis[v]=dis[u]+time;
                    pq.push({dis[v],v});
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(dis[i]==inf) return -1;
            minTime=max(minTime,dis[i]);
        }
        return minTime;
    }
};
