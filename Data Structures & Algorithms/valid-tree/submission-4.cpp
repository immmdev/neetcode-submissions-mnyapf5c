class Solution {
public:
    class DisjointSet{
        public:
        vector<int>rank,parent;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            // each no. is different set
            // all ranks are 0 (means depth)
            for(int i=0; i<n; i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(u==parent[u]) {return u;}
            // finding and reducing search overhead
            return parent[u]=findParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int prt_u=findParent(u);
            int prt_v=findParent(v);
            if(prt_u==prt_v)return;
            if(rank[prt_u]>rank[prt_v]){
                parent[prt_v]=prt_u;
            }
            // connecting parents because we dont have to do anything with children
            else if(rank[prt_u]<rank[prt_v]){
                parent[prt_u]=prt_v;
            }
            else {
                parent[prt_v]=prt_u;
                rank[prt_u]++;
            }
        }
    };

    bool isCycle(int src,int prt,vector<vector<int>>&adj,vector<int>&vis){
        vis[src]=1;
        for(auto child:adj[src]){
            if(vis[child]!=1){
                if(isCycle(child,src,adj,vis)) return true;
            // if node is visited then it must be parent else it is cycle
            } else if(child!=prt) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
         DisjointSet ds(n);
        for(auto it:edges){
            // undirected graph
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // creating connected component
        for(auto it:edges){
            ds.unionByRank(it[0],it[1]);
        }
        // detect is cycle
        bool flag=false;
        for(int i=0; i<n; i++){
            if(vis[i]!=1){
                flag=isCycle(i,-1,adj,vis);
            }
            if(flag==true) break;
        }

        set<int>st;
        for(int i=0; i<n; i++){
            int parent=ds.findParent(i);
            st.insert(parent);
        }
        bool isConnected=true;
        if(st.size()>1){
            isConnected=false;
        }

        return isConnected && !flag;

    }
};




