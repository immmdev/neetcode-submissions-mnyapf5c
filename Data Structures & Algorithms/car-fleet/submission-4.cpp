class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        // creating a vector with {position,speed} pair
        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(), cars.end()); // sorting cars in ascending order based on their position.
        stack<pair<int,int>>st;
        // we will satrt from right most pair as that pair with max position on the road
        // first we check that can car behind the right car is reachable or not, if reachable then pop out from the stack else compare with car just behind the right most car do it for all cars in the cars vector, at the end return the size of the stack as no of fleets.
        st.push(cars[cars.size()-1]);
        for(int i=cars.size()-2; i>=0; i--){
            auto topcar=st.top();
            int toppos=topcar.first;
            int topspeed=topcar.second;
            double t1=(double)(target-toppos)/topspeed;

            auto secondcar=cars[i];
            int secondpos=secondcar.first;
            int secondspeed=secondcar.second;
            double t2=(double)(target-secondpos)/secondspeed;
            if(t2>t1){
                st.push(cars[i]);
            } 
        }
        
        return st.size();
    }
};
