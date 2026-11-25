class Solution {
public:
    typedef long long ll;
    int m = 1e9 + 7;

    ll findpower(ll a, ll base){

        if(base == 0){
            return 1;
        }

        ll half = findpower(a, base/2);
        ll result = (half * half)%m;
        if(base % 2 == 1){
            result = (result * a) %m;
        }

        return result;
    }
    bool check(vector<int> &nums, int size, int base){

        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;
        ll p = findpower(base, size - 1);

        int i = 0; 
        int j = 0;

        while(j < n){

            hash = (hash * base + nums[j]) % m;

            if(j-i+1 < size){
                j++;
            }
            else{
                mp[hash]++;
                hash = (hash - (p*nums[i])%m + m)%m;
                i++;
                j++;
            }
        }

        for(auto &it : mp){
            if(it.second == 1){
                return true;
            }
        }

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;

        int l = 1;
        int r = n;

        int result = n;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)){
                result = mid;
                r = mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return result;
    }
};