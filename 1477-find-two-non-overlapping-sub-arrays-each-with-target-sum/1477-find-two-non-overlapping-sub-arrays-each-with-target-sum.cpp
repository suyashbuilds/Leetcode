class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();

        int i=0;
        int j = 0;
        int currsum = 0;

        vector<int> minlentillidx(n, INT_MAX);
        int bestminlen = INT_MAX;
        int ans = INT_MAX;
        
        while(j<n){

            currsum += arr[j];
            while(i <= j && currsum > target){
                currsum -= arr[i];
                i++;
            }

            if(currsum == target){
                int len = j-i+1;

                if(i>0 && minlentillidx[i-1] != INT_MAX){
                    ans = min(ans, len + minlentillidx[i-1]);
                }
                bestminlen = min(bestminlen, len);
            }
            minlentillidx[j] = bestminlen;
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};