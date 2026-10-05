class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int n = s.size();

        int score = 0;
        vector<int> ans;

        for(int i=0; i<n; i++){

            if(s[i] == '('){
                ans.push_back(score);
                score = 0;
            }
            else{
                if(s[i-1] == '('){ // this means "()" is found so score will be +1
                    score = ans.back() + 1;
                }
                else{
                    score = ans.back() + (2*score);
                }
                ans.pop_back();
            }
        }
        return score;
        
    }
};