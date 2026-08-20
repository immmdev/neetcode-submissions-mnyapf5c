class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(auto point:points){
            int x1=abs(point[0]);
            int y1=abs(point[1]);
            int x2=0;
            int y2=0;
            double d = sqrt(
                (double)(x1 - x2) * (x1 - x2) +
                (double)(y1 - y2) * (y1 - y2)
            );
            pq.push({d,{point[0],point[1]}});
        }
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();        
            }
            return ans;
    }
};
