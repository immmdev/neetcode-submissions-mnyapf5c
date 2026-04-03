class TimeMap {
    private:
        map<string,vector<pair<int,string>>>tMap;
    public:
        TimeMap() {}
        void set(string key, string value, int timestamp) {
            tMap[key].push_back({timestamp,value});
        }
        
        string get(string key, int timestamp) {
            auto res=tMap[key];
            if(tMap.find(key)==tMap.end()) return "";
            int l=0;
            int h=res.size()-1;
            string result="";
            while(l<=h){
                int mid=(l+h)/2;
                auto node=res[mid];
                if(node.first>timestamp){
                    h=mid-1;
                } else {
                    l=mid+1;
                    result=node.second;
                }
            }
            return result;
        }
};
