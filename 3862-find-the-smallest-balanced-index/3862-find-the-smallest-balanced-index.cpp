class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int n = nums.size();

        long long s = 0;
        for(int x : nums){
            s += x;
        }

        long long p = 1;
        int ans = -1;

        for(int i=n-1; i>=0; i--){

            s -= nums[i];

            if(s==p){
                ans = i;
            }

            if(p > LLONG_MAX/nums[i]){
                break;
            }

            p *= nums[i];

            if(p >= s){
                break;
            }
        }

        return ans;
    }
};