class Solution {
public:
    int solve(int i, int &n, vector<int>& costs, vector<int> &dp){

        if(i >= n-1){
            return 0;
        }

        if(dp[i+1] != -1){
            return dp[i+1];
        }

        int mini = INT_MAX;

        for(int j = i+1; j <= min(i+3, n-1); j++){
            mini = min(mini, (j-i)*(j-i) + costs[j] + solve(j,n,costs,dp));
        }

        return dp[i+1] = mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return solve(-1,n,costs,dp);
    }
};