class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>id(numCourses+1,0);
        
        for(auto it:adj){
         for(int i=0; i<it.second.size(); i++){
            id[it.second[i]]++;
        }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(id[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(id[node]==0) topo.push_back(node);
            for(auto it:adj[node]){
                id[it]--;
                if(id[it]==0)q.push(it);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};
