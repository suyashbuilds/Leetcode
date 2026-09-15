class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto &it : mp){

            if(it.second.size() < 3){
                continue;
            }

            auto &a = it.second;

            int diff = a[1] - a[0];
            bool found = true;

            for(int i=2; i<a.size(); i++){
                if((a[i] - a[i-1]) != diff){
                    found = false;
                    break;
                }
            }

            if(found){
                ans++;
            }
        }

        return ans;
    }
};