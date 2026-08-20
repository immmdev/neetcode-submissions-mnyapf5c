class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // give max at the top
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int n1=pq.top();
            pq.pop();
            int n2=pq.top();
            pq.pop();
            // destroying each other push the pq again to check the top two max.
            int diff1=n1-n2;
            int diff2=n2-n1;
            // pushing only if res greater than 0 else destroyed.
            if(diff1>0) pq.push(diff1);
            if(diff2>0) pq.push(diff2);
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }
};
