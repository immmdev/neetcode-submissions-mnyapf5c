class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>f;
        for(int i=0; i<tasks.size(); i++){
            f[tasks[i]]++;
        }
        // {freq,task}
        priority_queue<pair<int,char>>pq;
        for(auto it: f){
            pq.push({it.second,it.first});
        }
        // {task,{freq,callbacktime}}
        queue<pair<char,pair<int,int>>>q;
        int time=0;
        // if pq empty means no task here to implemnt cpu is idle
        while(!pq.empty() || !q.empty()){
            time=time+1; // time will increase no matter either the task executed or cpu was idle
            if(!pq.empty()){
                auto node=pq.top();
                pq.pop(); // task gone to the cpu, considering only one unit of time taken by cpu for the task to execute. 
                int cf=node.first;
                cf--;
                if(cf>0)q.push({node.second,{cf,time+n}});
            }
            if(!q.empty() && q.front().second.second==time){
                // re push the task as cooling period completed of the cpu
                auto fe=q.front();
                q.pop();
                pq.push({fe.second.first,fe.first});
            }

        }
        return time; // total time taken by cp to execute all the tasks

    }
};
