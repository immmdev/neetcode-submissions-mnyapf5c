class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return {{""}};
        map<string,vector<int>>f;
        vector<string>temp=strs;
        for(int i=0; i<n; i++){
            sort(temp[i].begin(),temp[i].end());
            f[temp[i]].push_back(i);
        }
        vector<vector<string>>res;
        for(auto it:f){
            vector<string>temp;
            for(int i=0; i<it.second.size(); i++){
                temp.push_back(strs[it.second[i]]);
            }
            res.push_back(temp);
        }

        return res;
    }
};
