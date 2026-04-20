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
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it:edges){
            ds.unionByRank(it[0],it[1]);
        }
        set<int>st;
        for(int i=0; i<n; i++){
            st.insert(ds.findParent(i));
        }
        return st.size();
    }
};
