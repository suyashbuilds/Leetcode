class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int n = s.size();
        int count = 1;
        int maxi = 1;
        if(n==0){
            return 0;
        }
        // vector<int> nums(n);
        // for(int i=0; i<n; i++){
        //     nums[i] = (int)s[i];
        // }

        for(int i=0; i<n-1; i++){
            if(s[i+1] == s[i] + 1){
                count++;
            }
            else{
                count = 1;
            }

            maxi = max(count,maxi);
        }
        return maxi;
    }
};