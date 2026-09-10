class Solution {
public:
    int m = 1e9+7;
    int dp[2001];
    vector<int> prev;
    int solve(int n){
        if(n==0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int total = (2*solve(n-1)) % m;

        if(prev[n] != 0){
            int duplicates = solve(prev[n] - 1);
            total =(total - duplicates + m) % m;
        }

        return dp[n] = total;
    }
    int distinctSubseqII(string s) {
        
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastseen(26,0);

        for(int i=1; i<=n; i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }

        return (solve(n) - 1 + m)%m;
    }
};