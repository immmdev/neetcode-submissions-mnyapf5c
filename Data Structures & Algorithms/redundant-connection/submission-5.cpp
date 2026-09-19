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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // if both father is same then it means redundant connection
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it:edges){
            if(ds.findParent(it[0])==ds.findParent(it[1])) return {it[0],it[1]};
            ds.unionByRank(it[0],it[1]);
        }

        return {};
    }
};
