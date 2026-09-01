class Solution {
public:
    vector<int> ans;
    void solve(int n, int num){

        if(num > n){
            return;
        }

        if(num <= n){
            ans.push_back(num);
        }

        for(int i=0; i<=9; i++){
            solve(n, num*10 + i);   
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1; i<=9; i++){
            solve(n,i);
        }

        return ans;
    }
};