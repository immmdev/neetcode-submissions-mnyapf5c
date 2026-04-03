class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>f;
        int n=nums.size();
        for(int i=0; i<n; i++){
            f[nums[i]]++;
        }
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        for(auto it:f){
            pq.push({it.second,it.first});
        }

        for(int i=0; i<k; i++){
            auto node=pq.top();
            pq.pop();
            res.push_back(node.second);
        }
        return res;
    }
};
