class Solution {
public:
    string largestMerge(string word1, string word2) {
        
        int i = 0;
        int j = 0;

        string res = "";

        while(i < word1.size() && j < word2.size()){

            if(word1[i] > word2[j]){
                res += word1[i];
                i++;
            }
            else if(word1[i] < word2[j]){
                res += word2[j];
                j++;
            }

            else{
                if(word1.substr(i) > word2.substr(j)){
                    res += word1[i];
                    i++;
                }
                else{
                    res += word2[j];
                    j++;
                }
            }
        }

        while(i<word1.size()){
            res+=word1[i];
            i++;
        }
        while(j<word2.size()){
            res+=word2[j];
            j++;
        }

        return res;
    }
};