class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(k<stops) continue;
            for(auto it : adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[v]>dis+wt && stops<=k){
                    dist[v]=dis+wt;
                    q.push({stops+1,{v,dist[v]}});
                }
                
            }
        }
        
    if(dist[dst]==1e9) return -1; 
    return dist[dst];
    
    }
};
