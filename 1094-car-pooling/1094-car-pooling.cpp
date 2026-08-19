class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> timeline(10001, 0);

        for(auto &trip : trips){
            timeline[trip[1]] += trip[0]; // trip[1] is start location, trip[0] is numPassengers
            timeline[trip[2]] -= trip[0]; // trip[2] is end location
        }

        int count = 0;

        for(auto &p : timeline){
            count += p;
            if(count > capacity){
                return false;
            }
        }
        return true;
    }
};