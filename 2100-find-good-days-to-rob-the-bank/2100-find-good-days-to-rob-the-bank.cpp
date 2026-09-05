class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        int n = security.size();

        int count = 0;
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 0;
        for(int i=1; i<n; i++){
            if(security[i]<=security[i-1]){
                count++;
            }
            else{
                count=0;
            }
            prefix[i] = count;
        }

        count = 0;
        suffix[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            if(security[i] <= security[i+1]){
                count++;
            }
            else{
                count=0;
            }
            suffix[i] = count;
        }

        vector<int> arr;
        for(int i=0; i<n; i++){
            if(prefix[i] >= time && suffix[i] >= time){
                arr.push_back(i);
            }
        }
        return arr;
    }
};