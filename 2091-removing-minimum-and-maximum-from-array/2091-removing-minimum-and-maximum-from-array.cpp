class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_index = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(min_index,max_index);
        int right = max(min_index,max_index);

        return min({left+1 + n-right, right+1, n-left});
    }
};