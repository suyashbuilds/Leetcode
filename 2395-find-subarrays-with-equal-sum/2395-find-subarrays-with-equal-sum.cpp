class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int> st;

        for(int i=0; i<n-1; i++){
            int count = 0;
            for(int j=i; j<i+2; j++){
                count+=nums[j];
            }
            if(st.contains(count)){
                return true;
            }
            st.insert(count);
        }
        return false;
    }
};