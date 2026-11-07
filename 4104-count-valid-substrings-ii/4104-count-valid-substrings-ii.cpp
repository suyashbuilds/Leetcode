class Solution {
public:
    long long countValidSubstrings(string s) {
        
        int n = s.size();

        long long a = -1;
        long long ab = -1;
        long long abc = -1;

        long long ans = 0;

        for(int i=0; i<n; i++){
            
            if(s[i] == 'a'){
                a = i;
            }

            else if(s[i] == 'b'){
                if(a != -1){
                    ab = max(ab, a);
                }
            }

            else if(s[i] == 'c'){
                if(ab != -1){
                    abc = max(abc, ab);
                }
            }

            ans += (i-abc);
        }

        return ans;
    }
};