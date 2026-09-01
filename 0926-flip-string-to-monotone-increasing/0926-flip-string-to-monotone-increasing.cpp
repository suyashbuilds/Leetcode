class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int countofones = 0;
        int flip = 0;

        for(char c : s){
            if(c == '1'){
                countofones++;
            }
            else{
                flip = min(flip+1, countofones);
            }
        }
        return flip;
    }
};