class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            int size = 0;
            int sum = 0;

            for(int j=i; j<n; j++){
                sum += nums[j];
                size++;

                if(sum > 0 && size >= l && size <= r){
                    ans = min(ans, sum);
                }
            }
        }

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};