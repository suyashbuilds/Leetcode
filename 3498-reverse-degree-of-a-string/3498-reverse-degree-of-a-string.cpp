class Solution {
public:
    int reverseDegree(string s) {
        
        int n = s.size();

        int i=0;
        int j = 1;
        int sum = 0;
        while(i<n){
            char ch = s[i];
            int x = -(ch-'z') + 1;
            int pro = x*j;
            sum += pro;
            i++;
            j++;
        }
        return sum;
    }
};