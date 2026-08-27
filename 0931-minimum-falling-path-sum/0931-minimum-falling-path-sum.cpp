class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& matrix, int n){

        if(j<0 || j>=n){
            return INT_MAX;
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        if(i == n-1){
            return dp[i][j] = matrix[i][j];
        }

        int down = solve(i+1, j, matrix, n);
        int leftdown = solve(i+1, j-1, matrix, n);
        int rightdown = solve(i+1, j+1, matrix, n);

        return dp[i][j] = matrix[i][j] + min({down, leftdown, rightdown});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = INT_MAX;
            }
        }
        int ans = INT_MAX;

        for(int j=0; j<n; j++){
            ans = min(ans, solve(0, j, matrix, n));
        }

        return ans;
    }
};