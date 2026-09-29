class Solution {
public:
    int n, m;
    int dp[101][101][201];
    bool solve(vector<vector<char>> &grid, int i, int j, int count){

        if( i>=n || j>=m){
            return false;
        }

        if(count < 0){
            return false;
        }

        if(i == n-1 && j == m-1){
            if(grid[i][j] == ')' && count == 1){
                return true;
            }

            else{
                return false;
            }
        }

        if(dp[i][j][count] != -1){
            return dp[i][j][count];
        }

        int x = count;
        if(grid[i][j] == '('){
            x++;
        }
        else{
            x--;
        }

        return dp[i][j][count] = solve(grid, i+1, j, x) || solve(grid, i, j+1, x);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        if(grid[0][0] == ')' || grid[n-1][m-1] == '('){
            return false;
        }

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0 , 0);

    }
};