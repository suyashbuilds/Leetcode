class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(nums[i] % k == 0){
                st.insert(nums[i] / k);
            }
        }

        for(int i = 1; i<=st.size(); i++){
            if(st.find(i) == st.end()){
                return k*i;
            }
        }

        return k*(st.size() + 1);
    }
};