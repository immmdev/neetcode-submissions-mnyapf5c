class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int cost = cur[0], node = cur[1], stops = cur[2];

            if(node == dst) return cost;

            if(stops > k) continue;

            for(auto &it : adj[node]){
                int next = it.first;
                int price = it.second;

                if(cost + price < dist[next][stops+1]){
                    dist[next][stops+1] = cost + price;
                    pq.push({cost + price, next, stops+1});
                }
            }
        }

        return -1;
    }
};