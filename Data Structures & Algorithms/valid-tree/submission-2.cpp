class DisjointSet{
    
    public:
        vector<int>rank,parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i]=i;
            }
        }

        int findParent(int node){
            if(parent[node]==node)return node;
            return parent[node]=findParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int prt_u=findParent(u);
            int prt_v=findParent(v);
            if(prt_u==prt_v)return;

            if(rank[prt_v]>rank[prt_u]){
                parent[prt_u]=prt_v;
            } else if (rank[prt_v]<rank[prt_u]){
                parent[prt_v]=prt_u;
            } else{
                parent[prt_u]=prt_v;
                rank[prt_v]++;
            }
        }
};

bool detectcycle(int src, int p, vector<vector<int>>&adj, vector<int>&vis){
    vis[src]=1;
    for(auto it:adj[src]){
        if(vis[it]!=1){
            if(detectcycle(it,src,adj,vis)) return true;
        } else if(it!=p) return true;
    }
    return false;
}
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
          vector<int>vis(n,0);
          vector<vector<int>>adj(n);
          for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
          }

          DisjointSet ds(n);

          for(auto it:edges){
            ds.unionByRank(it[0],it[1]);
          }
        bool flag = false;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(detectcycle(i, -1, adj, vis)){
                flag = true;
                break;
            }
        }
    }
        set<int>st;
        for(int i=0; i<n; i++){
            int p=ds.findParent(i);
            st.insert(p);
        }

        bool connected=st.size()>1?false:true;
        return connected && !flag;
    }
};
