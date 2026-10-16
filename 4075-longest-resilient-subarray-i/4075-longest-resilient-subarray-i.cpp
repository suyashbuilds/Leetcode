class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 1;

        for(int i=0; i<n; i++){

            int mod = nums[i] % k;

            long long sum = nums[i];

            for(int j=i+1; j<n; j++){

                sum += nums[j];

                if(nums[j] % k != mod){
                    break;
                }

                if(((nums[j] % k) != mod) || ((sum % k) != mod)){
                    continue;
                }

                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};