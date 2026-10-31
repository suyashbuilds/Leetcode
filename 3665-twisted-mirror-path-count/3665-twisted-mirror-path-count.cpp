class Solution {
public:
    int left = 0; // came from left and going right
    int up = 1; // came from up and going down
    int n, m;
    int mod = 1e9 + 7;
    //momoization == changes in i and j alongwith camefrom so lets take camefrom{-1,-1}
    int solve(vector<vector<int>>& grid, int i, int j, int camefrom, vector<vector<array<int, 2>>> &dp){

        if(i >= n || j >= m){
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }

        if(dp[i][j][camefrom] != -1){
            return dp[i][j][camefrom];
        }

        if(grid[i][j] == 1){ //mirror found
            if(camefrom == left){
                return dp[i][j][camefrom] = solve(grid, i+1,j, up, dp);
            }
            else{
                return dp[i][j][camefrom] = solve(grid, i, j+1, left, dp);
            }
        }

        // when grid[i][j] == 0 i.e. mirror not found 
        int total = 0;
        total = (total + solve(grid, i, j+1, left, dp)) % mod;
        total = (total + solve(grid, i+1, j, up, dp)) % mod;

        return dp[i][j][camefrom] = total;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        vector<vector<array<int, 2>>> dp(n+1, vector<array<int,2>>(m+1, {-1,-1}));
        return solve(grid, 0, 0, left, dp);
    }
};