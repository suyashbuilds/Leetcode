class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, string &t, int &n, int &m, int i, int j){

        if(j == m){
            return 1;
        }

        if(i == n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, n, m, i+1, j+1) + solve(s,t,n,m,i+1,j);
        }
        else{
            return dp[i][j] = solve(s,t,n,m,i+1,j);
        }
    }
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        memset(dp, -1, sizeof(dp));
        return solve(s,t, n, m, 0, 0);
    }
};