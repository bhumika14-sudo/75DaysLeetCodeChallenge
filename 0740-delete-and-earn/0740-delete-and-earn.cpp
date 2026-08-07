class Solution {
public:
    // int solve(vector<int>& points, int i, vector<int>& dp){
    //     if(i >= points.size()) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int notTake = solve(points, i+1, dp);
    //     int take = points[i] + solve(points, i+2, dp);
    //     return dp[i] = max(take, notTake);
    // }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> points(maxi+1, 0);
        for(int num : nums){
            points[num] += num;
        }
        vector<int> dp(maxi + 3, 0);

        for(int i=maxi ; i>=0; i--){
            int take = points[i] + dp[i+2];
            int notTake = dp[i+1];
            dp[i] = max(take, notTake);
        }
        // return solve(points, 0, dp);
        return dp[0];
    }
};