class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        int l = 0;
        int r = 0;
        int one = 0;

        string res = "";

        while(r<n){

            if(s[r] == '1'){
                one++;
            }
            while(one>k){
                if(s[l] == '1'){
                    one--;
                }
                l++;
            }

            if(one==k){
                while(s[l] == '0'){
                    l++;
                }
                string ans = s.substr(l,r-l+1);
                if (res.empty() || res.length() > ans.length() || (res.length() == ans.length() && ans < res)) {
                    res = ans;
                }
            }
            r++;
        }
        return res;
    }
};