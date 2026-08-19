class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int, bool> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]] = true;
        }

        for(int i=1; i<=n; i++){
            if(mp[i] == false){
                return i;
            }
        }
        //If 1 to n are all present, n + 1 is missing
        return n+1;
    }
};