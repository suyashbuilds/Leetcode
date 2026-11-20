class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int findmethod(int start, int target, vector<int> &nums){

        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();

        if(j<n && nums[j] == target){
            return j;
        }

        return -1;
    }
    int solve(int i, int inc, vector<int> &nums){

        int currval = nums[i]+ inc;

        int len = 1;

        if(dp[i][inc] != -1){
            return dp[i][inc];
        }

        // 1st option = find currval + 1 directly
        int j = findmethod(i+1, currval+1, nums);
        if(j != -1){
            len = max(len, 1 + solve(j, 0, nums));
        }

        // 2nd option = find currval and then increment 1 
        j = findmethod(i+1, currval, nums);
        if(j != -1){
            len = max(len, 1 + solve(j, 1, nums));
        }

        return dp[i][inc] = len;

    }
    int maxSelectedElements(vector<int>& nums) {
        
        n = nums.size();

        dp.assign(n+1, vector<int> (2, -1));

        sort(nums.begin(), nums.end());

        int result = 1;

        for(int i=0; i<n; i++){
            result = max({solve(i, 0, nums), solve(i, 1, nums), result});
        }

        return result;
    }
};