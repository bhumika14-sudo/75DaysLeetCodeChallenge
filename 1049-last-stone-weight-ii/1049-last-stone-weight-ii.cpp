class Solution {
public:
    // int solve(int i, vector<int>& stones, int target, vector<vector<int>>& dp){
    //     int n = stones.size();
    //     if(i==n) return 0;
    //     if(target==0) return 0;

    //     if(dp[i][target] != -1) return dp[i][target];

    //     int notTake = solve(i+1, stones, target, dp);
    //     int take = 0;
    //     if(stones[i] <= target){
    //         take = stones[i] + solve(i+1, stones, target-stones[i], dp);
    //     }
    //     return dp[i][target] = max(take, notTake);
    // }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(int x : stones){
            total += x;
        }
        int target = total/2;
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // int subsetSum = solve(0, stones, target, dp);
        // return total - 2*subsetSum;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j = 0; j <= target; j++) {
                int notTake = dp[i+1][j];
                int take = 0;
                if(stones[i] <= j){
                    take = stones[i] + dp[i+1][j - stones[i]];
                }
                dp[i][j] = max(take, notTake);
            }    
        }
        return total - 2*dp[0][target];
    }
};