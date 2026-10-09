class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();

        int i = 0;
        int count = 0;
        int result = 0;

        while(i<n){

            if(s[i] == '('){
                count++;
                i++;
            }
            else{ // ")" ye mil gaya
                if(count > 0){//( ye pehle tha
                    count--;
                }
                else{
                    // ( ye nahi tha to isko add karna h 
                    result++;
                }

                if(i+1<n && s[i+1] == ')'){
                    i+=2;
                }
                else{
                    result++; // ) add kardenge
                    i++;
                }
            }
        }
        return result + 2*count; // kyunki har open bracket ke liye 2 closing bracket hain
    }
};