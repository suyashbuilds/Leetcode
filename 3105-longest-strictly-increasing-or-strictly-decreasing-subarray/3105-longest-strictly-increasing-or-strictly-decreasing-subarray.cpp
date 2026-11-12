class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;

        //increasing
        for(int i=0; i<n; i++){
            int currlength = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[j-1]){
                    currlength++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi, currlength);
        }

        //decreasing
        for(int i=0; i<n; i++){
            int currlength = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j] < nums[j-1]){
                    currlength++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi, currlength);
        }

        return maxi;
    }
};