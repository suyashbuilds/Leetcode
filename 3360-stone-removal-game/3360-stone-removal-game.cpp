class Solution {
public:
    bool canAliceWin(int n) {
        
        int start = 10;
        int step = 0;

        while(n >= start){
            n -= start;
            start -= 1;
            step++;
        }

        return (step % 2 == 1);
    }
};