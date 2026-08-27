class Solution {
public:
    //long long dp[101][101];
    long long solve(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp, int n){

        if(j<0 || j>=n){
            return LLONG_MAX;
        }

        if(i == n-1){
            return dp[i][j] = grid[i][j];
        }

        if(dp[i][j] != LLONG_MAX){
            return dp[i][j];
        }

        long long ans = LLONG_MAX;
        for(int k=0; k<n; k++){
            if(k!=j){
                ans = min(ans, solve(i+1, k, grid, dp, n));
            }
        }

        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         dp[i][j] = LLONG_MAX;            
        //     }
        // }

        vector<vector<long long>> dp(
            n, vector<long long>(n, LLONG_MAX)
        );

        long long ans = LLONG_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, solve(0, j, grid, dp, n));
        }

        return ans;
    }
};