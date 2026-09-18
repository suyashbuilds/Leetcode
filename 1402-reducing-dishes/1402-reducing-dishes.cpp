class Solution {
public:
    int n;
    int dp[1002][1002];
    int solve(vector<int> &satisfaction, int i, int t, int &n){

        if(i==n){
            return 0;
        }

        if(dp[i][t] != -1){
            return dp[i][t];
        }

        int include = (satisfaction[i] * t) + solve(satisfaction, i+1, t+1, n);
        int exclude = solve(satisfaction, i+1, t, n);

        return dp[i][t] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        memset(dp, -1, sizeof(dp));

        return solve(satisfaction, 0,1,n);
    }
};