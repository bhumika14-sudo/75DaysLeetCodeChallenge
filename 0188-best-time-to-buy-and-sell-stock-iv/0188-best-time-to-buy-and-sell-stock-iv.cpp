class Solution {
public:
    // int solve(int i, int k , vector<int>& prices, int buy, vector<vector<vector<int>>>& dp){
    //     if(i == prices.size() || k==0){
    //         return 0;
    //     }
    //     if(dp[i][buy][k] != -1){
    //         return dp[i][buy][k];
    //     }
    //     if(buy == 0){
    //         int take = -prices[i]+solve(i+1, k, prices, 1, dp);
    //         int skip = solve(i+1, k, prices, 0, dp);
    //         return dp[i][buy][k] = max(take,skip);
    //     }
    //     if(buy == 1){
    //         int sell = prices[i] + solve(i+1, k-1, prices, 0, dp);
    //         int hold = solve(i+1, k, prices, 1, dp);
    //         return dp[i][buy][k] = max(sell, hold);
    //     }
    //     return 0;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        dp[n][0][0] = 0;
        dp[n][1][0] = 0;

        for(int i=n-1; i>=0; i--){
            for(int count = 1; count <=k ; count++){
                dp[i][0][count] = max(-prices[i] + dp[i+1][1][count], dp[i+1][0][count]);
                dp[i][1][count] = max(prices[i] + dp[i+1][0][count-1] , dp[i+1][1][count]);
            }
        }
        return dp[0][0][k];
        // return solve(0, k, prices, 0, dp);
    }
};