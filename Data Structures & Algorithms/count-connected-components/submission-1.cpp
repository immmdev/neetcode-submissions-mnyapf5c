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

    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it: edges){
            ds.unionByRank(it[0],it[1]);
        }

        set<int>st;
        for(int i=0; i<n; i++){
            st.insert(ds.findParent(i));
        }

        return st.size();
    }
};
