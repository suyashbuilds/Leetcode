class Solution {
public:
    int m = 1e9+7;
    int sumDecoded(vector<long long>& nums) {
        
        long long total = 0;

        for(long long num : nums){
            int width = num%10;
            long long d = num/10;
            string s = to_string(d);

            long long x = stoll(s.substr(0,width))%m;
            long long y = stoll(s.substr(width));

            long long b = x%m;
            long long pow = y;
            long long res = 1;

            while (pow > 0) {
                if(pow % 2 == 1) {
                    res = (res * b) % m;
                }
                b = (b * b) % m;
                pow /= 2;
            }
            total = (total + res) % m;
        }
        return total; 
    }
};