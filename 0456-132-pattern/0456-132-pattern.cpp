class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans;
        int second = INT_MIN;

        for(int i = n-1; i>=0; --i){

            if(nums[i] < second){
                return true;
            }

            while(!ans.empty() && nums[i] > ans.back()){
                second = ans.back();
                ans.pop_back();
            }

            ans.push_back(nums[i]);
        }
        return false;
    }
};