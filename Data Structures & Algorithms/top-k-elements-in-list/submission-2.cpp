class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int n=nums.size();
        for(int i=0; i<n; i++){
            f[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto it:f){
            bucket[it.second].push_back(it.first);
        }
        
        vector<int>res;
        for(int i=n; i>=0; i--){
            
            for(int j=0; j<bucket[i].size(); j++){
                res.push_back(bucket[i][j]);
                if(res.size()==k) return res;
            }
        }
        // return res;
    }
};
