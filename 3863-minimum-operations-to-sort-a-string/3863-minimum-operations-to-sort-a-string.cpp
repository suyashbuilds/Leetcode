class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();

        if(is_sorted(s.begin(), s.end())){
            return 0;
        }

        if(n==2) return -1;

        char mini = 'z';
        char maxi = 'a';

        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            mini = min(s[i], mini);
            maxi = max(s[i], maxi);
            freq[s[i]-'a']++;
        }

        if(s[0] == mini || s[n-1] == maxi){
            return 1;
        }

        if(s[n-1] == mini && freq[maxi-'a'] == 1 && s[0] == maxi && freq[mini-'a'] == 1){
            return 3;
        }

        return 2;
    }
};