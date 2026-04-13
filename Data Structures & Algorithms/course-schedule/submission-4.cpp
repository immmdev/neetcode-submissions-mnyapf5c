class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        int n=prerequisites.size();
        vector<vector<int>>adj(1000);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>id(numCourses+1,0);
        for(auto it:adj){
            int s=it.size();
            for(int i=0; i<s; i++){
                id[it[i]]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        stack<int>topo;
        while(!q.empty()){
        auto node=q.front();
        topo.push(node);
        q.pop();
        for(auto it:adj[node]){
            id[it]--;
            if(id[it]==0) q.push(it);
            }
        }

        if(topo.size()==numCourses)return true;
        return false;
    }
};