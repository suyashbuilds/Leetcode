class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        
        int n = nums.size();

        long long first = 0;
        long long second = 0;

        int half = n/2;

        for(int i=0; i<half; i++){
            first += nums[i];
        }
        for(int i=half; i<n; i++){
            second += nums[i];
        }

        int i=0;
        int count = 0;

        while(i<n){
            if(first > second){
                count++;
            }

            first -= nums[i%n];
            first += nums[(i+half)%n];
            second -= nums[(half+i)%n];
            second += nums[(n+i)%n];
            i++;
        }
        return count;
    }
};