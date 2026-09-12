class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string t = s + s;

        string d = t.substr(1, t.size()-2);

        return d.find(s) != string::npos;
    }
};