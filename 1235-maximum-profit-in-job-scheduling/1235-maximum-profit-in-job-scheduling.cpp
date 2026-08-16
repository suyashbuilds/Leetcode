class Solution {
public:
    int n;
    int dp[50001];
    //find the first job jiska starting time >= currentjob ka endtime;
    int getnextindex(vector<vector<int>> &array, int l, int currentjobend){

        int r = n-1;
        int result = n+1; //can take any value;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(array[mid][0] >= currentjobend){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
    }
    int solve(vector<vector<int>> &array, int i){
        if(i>=n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int next = getnextindex(array, i+1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);

        return dp[i] = max(taken, notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        n = startTime.size();

        vector<vector<int>> arr(n, vector<int> (3,0)); //{s,e,p}

        for(int i=0; i<n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        auto comp = [&](auto &vec1, auto &vec2){
            return vec1[0] < vec2[0];
        };

        memset(dp, -1, sizeof(dp));
        sort(arr.begin(), arr.end(),comp);

        return solve(arr,0);
    }
};