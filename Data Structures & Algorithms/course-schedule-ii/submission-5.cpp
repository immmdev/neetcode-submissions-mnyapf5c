class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>adj;
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>incoming(numCourses+1,0);
        for(auto it : adj){
            auto s=it.second.size();
            for(int i=0; i<s; i++){
                incoming[it.second[i]]++;
            }
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(incoming[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(incoming[node]==0)topo.insert(topo.begin(), node);
            for(auto it:adj[node]){
                incoming[it]--;
                if(incoming[it]==0) q.push(it);
            }
        }
       
        if(topo.size()==numCourses) return topo;
        else return {};
    }
};
