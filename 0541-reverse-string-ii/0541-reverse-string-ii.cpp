class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n = s.size();

        for(int i=0; i<n; i+=2*k){

            int last = min(i+k, (int)s.size());
            reverse(s.begin() + i, s.begin() + last);
        }
        return s;
    }
};