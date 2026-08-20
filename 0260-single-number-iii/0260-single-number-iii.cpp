class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mp;

        for(int x : nums){
            mp[x]++;
        } 

        for(auto &it : mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};