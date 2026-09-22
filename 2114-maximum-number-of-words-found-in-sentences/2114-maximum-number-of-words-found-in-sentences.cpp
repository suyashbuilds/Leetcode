class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maxi = 0;
        for(auto &s : sentences){
            stringstream ss(s);
            string word;
            int count = 0;

            while(ss >> word){
                count++;
            }

            maxi = max(maxi, count);
        }
        return maxi;
    }
};