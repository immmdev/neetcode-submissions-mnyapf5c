class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF=10e4;
        vector<int>dist(n+1,INF);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // {dist,Node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        int mint=-1;
        while(!pq.empty()){
            auto el=pq.top();
            int dis=el.first;
          
            int node=el.second;
            pq.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int time=it.second;
                if(dist[node]+time<dist[v]){
                    dist[v]=dist[node]+time;
                    pq.push({dist[node]+time,v});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(dist[i]==INF){
                return -1;
            }
            mint=max(mint,dist[i]);
            
        }
        return mint;
    }
};
