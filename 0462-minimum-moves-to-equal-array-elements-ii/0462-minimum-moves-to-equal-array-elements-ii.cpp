class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        sort(begin(nums), end(nums));
        int mid = nums[n/2];

        for(int i=0; i<n; i++){
            count += abs(nums[i] - mid);
        }

        return count;
    }
};