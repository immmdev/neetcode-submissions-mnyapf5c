class LRUCache {
public:
    vector<pair<int,int>>lru;
    int cap=0;
    LRUCache(int capacity) {
        cap=capacity;
        lru.resize(capacity);
    }
    int get(int key) {
        int res=-1;
        int index=-1;
        for(int i=lru.size()-1; i>=0; i--){
            auto node=lru[i];
            int k=node.first;
            int v=node.second;
            if(key==k) {
                res=v;
                index=i;
                lru.erase(lru.begin() + index);
                lru.push_back({k,v});
                break;
            }
        }
        return res;
    }
    
    void put(int key, int value) {
        bool exist=false;
        for(int i=0; i<lru.size(); i++){
            auto node=lru[i];
            int k=node.first;
            int v=node.second;
            if(key==k){
                lru.erase(lru.begin() + i);
                lru.push_back({key, value});
                return;
            }
        }
        if(cap==lru.size()){
            lru.erase(lru.begin());
            lru.push_back({key,value});
        }
    }
};
