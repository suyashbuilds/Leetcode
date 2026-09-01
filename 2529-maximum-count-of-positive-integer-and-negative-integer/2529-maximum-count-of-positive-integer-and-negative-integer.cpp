class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcount = 0;
        int ncount = 0;

        for(int num : nums){
            if(num>0){
                pcount++;
            }
            else if(num<0){
                ncount++;
            }
        }
        return max(pcount, ncount);
    }
};