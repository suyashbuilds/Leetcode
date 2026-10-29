/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int solve(int start, int end){

        int mid = start + (end-start)/2;

        int ans = guess(mid);

        if(ans == -1){
            return solve(start, mid-1);
        }
        if(ans == 1){
            return solve(mid+1, end);
        }

        return mid;
    }
    int guessNumber(int n) {
        
        return solve(1,n);
    }
};