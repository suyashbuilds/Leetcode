class Solution {
public:
    int alternateDigitSum(int n) {
        
        int total = 0;
        int sign = 1;

        for(char ch : to_string(n)){
            total += sign * (ch - '0');
            sign *= -1;
        }
        return total;
    }
};