class DisjointSet{
    public:
        vector<int>parent,setsize;
        DisjointSet(int n){
            setsize.resize(n+1,1);
            parent.resize(n+1);
            for(int i=1; i<=n; i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(parent[node]==node)return node;
            return parent[node]=find(parent[node]);
        }

        void unionBySize(int u,int v){
            int prt_u=find(u);
            int prt_v=find(v);
            if(prt_u==prt_v)return;
            if(setsize[prt_u]>setsize[prt_v]){
                parent[prt_v]=prt_u;
                setsize[prt_u]+=setsize[prt_v];
            } else if(setsize[prt_u]<setsize[prt_v]){
                parent[prt_u]=prt_v;
                setsize[prt_v]+=setsize[prt_u];
            } else {
                parent[prt_u]=prt_v;
                setsize[prt_v]+=setsize[prt_u];
            }
        }
};
class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        DisjointSet ds(n);
       
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.find(u)==ds.find(v)){
                return {u,v};
            }
            ds.unionBySize(u,v);
            
        }
        return {};
    }
};
