class Solution {
public:
    int n,m;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int i, int j, vector<vector<int>> &grid){

        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(vector<int> &d  : directions){
            int i1 = i + d[0];
            int j1 = j + d[1];

            if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && grid[i1][j1] > 0){
                sum += dfs(i1, j1, grid);
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(i, j, grid);
                    if(sum %k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};