class Solution {
public:
    int getdigitsum(int num){

        int sum = 0;

        while(num > 0){
            int temp = num%10;
            sum += temp;
            num /= 10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        vector<int> aftersorted(nums);

        auto lambda = [&](int n1, int n2){

            int dsum1 = getdigitsum(n1);
            int dsum2 = getdigitsum(n2);

            if(dsum1 != dsum2){
                return dsum1<dsum2;
            }

            return n1<n2;
        };

        sort(aftersorted.begin(), aftersorted.end(), lambda);
        
        for(int i=0; i<n; i++){
            int expected_val = aftersorted[i];
            int currval = nums[i];

            if(expected_val == currval){
                continue;
            }

            int idx = mp[expected_val];

            nums[i] = expected_val;
            nums[idx] = currval;

            mp[expected_val] = i;
            mp[currval] = idx;

            count++;
        }

        return count;
    }
};