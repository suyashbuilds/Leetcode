class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;

        if(target < 0){
            return -1;
        }

        if(target == 0){
            return n;
        }

        int currsum = 0;
        int i = 0;
        int maxi = -1;

        for(int j=0; j<n; j++){
            currsum += nums[j];

            while(currsum > target && i <= j){
                currsum -= nums[i];
                i++;
            }

            if(currsum == target){
                maxi = max(maxi, j-i+1);
            }
        }

        return (maxi != -1) ? n-maxi : -1;
        
    }
};