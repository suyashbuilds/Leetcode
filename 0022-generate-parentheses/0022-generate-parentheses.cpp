class Solution {
public:
    void solve(int n, int l, int u, string s, vector<string> &ans){

        if(u == n){
            ans.push_back(s);
            return;
        }

        if(l<n){
            solve(n,l+1,u,s+"(",ans);
        }
        if(u<l){
            solve(n,l,u+1,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;

        solve(n, 0, 0, "", ans);
        return ans;
    }
};