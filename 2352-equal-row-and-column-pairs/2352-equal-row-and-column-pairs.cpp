class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        map<vector<int>, int> mp;

        for(int j=0; j<m; j++){
            vector<int> temp;

            for(int i=0; i<n; i++){
                temp.push_back(grid[i][j]);
            }

            mp[temp]++;
        }

        int ans = 0;
        for(auto &i : grid){
            ans += mp[i];
        }

        return ans;
    }
};