class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> nums2;

        int evencount = 0;
        int oddcount = 0;
        int firstoddindex = -1;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                evencount++;
            }
            else{
                oddcount++;
                if(firstoddindex == -1){
                    firstoddindex = i;
                }
            }
        }

        if(evencount == n || oddcount == n){
            return true;
        }
        
        //making all odd
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                nums2.push_back(nums[i] - nums[firstoddindex]);
            }
            else{
                nums2.push_back(nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums2[i] % 2 == 0){
                return false;
            }
        }

        return true;
    }
};