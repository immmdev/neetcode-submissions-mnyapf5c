class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dis(n, 1e9);

        // 🔥 IMPORTANT
        dis[src] = 0;

        // stops, {node, cost}
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto el = q.front(); q.pop();

            int stops = el.first;
            int node = el.second.first;
            int cost = el.second.second;

            if(stops > k) continue;

            for(auto it: adj[node]){
                int next = it.first;
                int wt = it.second;

                if(cost + wt < dis[next]){
                    dis[next] = cost + wt;
                    q.push({stops+1, {next, dis[next]}});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};