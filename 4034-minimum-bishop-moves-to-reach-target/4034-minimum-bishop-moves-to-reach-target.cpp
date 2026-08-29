class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        
        int i = source[0];
        int j = source[1];
        int k = target[0];
        int l = target[1];

        if(i==k && j==l){
            return 0;
        }

        if(i-j == k-l || i+j == k+l){
            return 1;
        }

        if ((i + j) % 2 != (k + l) % 2) {
            return -1;
        }

        return 2;
    }
};