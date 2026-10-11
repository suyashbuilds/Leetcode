class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long i = 0;
        long long j = sqrt(c);

        while(i<=j){

            long long currsum = i*i + j*j;

            if(currsum == c){
                return true;
            }
            else if(currsum < c){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};