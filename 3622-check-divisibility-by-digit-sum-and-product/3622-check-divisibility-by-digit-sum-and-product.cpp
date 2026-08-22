class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum = 0;
        int pro = 1;
        int x = n;
        while(n>0){
            int temp = n%10;
            sum += temp;
            pro *= temp;
            n /= 10;
        }

        int d = sum + pro;
        return x%d==0;
    }
};