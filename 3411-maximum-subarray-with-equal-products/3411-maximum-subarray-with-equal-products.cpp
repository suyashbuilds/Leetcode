class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int pro = nums[i];
            int gcd_val = nums[i];
            int lcm_val = nums[i];
            for(int j = i+1; j<n; j++){
                pro *= nums[j];
                gcd_val = gcd(gcd_val, nums[j]);
                lcm_val = lcm(lcm_val, nums[j]);

                if(pro > gcd_val * lcm_val){
                    break;
                }

                if(pro == gcd_val * lcm_val){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};