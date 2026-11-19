class Solution {
public:
    int countConsistent(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int a = nums[i];
            int mini = nums[i];

            if(a == mini){
                ans++;
            }

            for(int j=i+1; j<n; j++){
                a &= nums[j];
                mini = min(nums[j], mini);
                if(a == mini){
                    ans++;
                }
            }
        }
        return ans;
    }
};