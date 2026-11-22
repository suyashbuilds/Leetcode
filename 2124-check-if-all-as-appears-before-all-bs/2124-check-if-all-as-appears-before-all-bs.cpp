class Solution {
public:
    bool checkString(string s) {
        
        int n = s.size();

        if(n == 1) {
            return true;
        }

        int index = n;
        for(int i=0; i<n; i++){
            
            if(s[i] == 'b'){
                index = i;
                break;
            }
        }

        for(int j = index; j<n; j++){
            if(s[j] == 'a'){
                return false;
            }
        }
        return true;

    }
};