class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k){
            string temp;

            int n = s.size();

            for(int i=0; i<n; i+=k){
                int ans = 0;
                for(int j=i; j< min(i+k, n); j++){
                    ans += s[j] - '0';
                }
                temp.append(to_string(ans));
            }
            s = temp;
        }

        return s;
    }
};