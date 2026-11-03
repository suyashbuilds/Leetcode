class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        int num = *max_element(nums.begin(), nums.end());

        for(auto x : nums){
            count += num-x;
        }

        return count;

    }
};