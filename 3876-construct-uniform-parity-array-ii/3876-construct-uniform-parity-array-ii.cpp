class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> nums2;

        int minodd = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 != 0){
                minodd = min(minodd, nums[i]);
            }
        }

        if(minodd == INT_MAX){
            return true;
        }

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                if(nums[i] < minodd){
                    return false;
                }
                nums2.push_back(nums[i] - minodd);
            }
            else{
                nums2.push_back(nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums2[i] % 2==0){
                return false;
            }
        }

        return true;
    }
};