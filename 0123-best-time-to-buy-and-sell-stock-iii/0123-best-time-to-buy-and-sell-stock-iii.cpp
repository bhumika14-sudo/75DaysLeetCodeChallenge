class Solution {
public:
    int solve(int i, vector<int>& prices, int buy, int count , vector<vector<vector<int>>>& dp){
        if(i == prices.size() || count==0){
            return 0;
        }
        if(dp[i][buy][count] != -1){
            return dp[i][buy][count];
        }
        //buy state 
        if(buy==0){
            int take = -prices[i] + solve(i+1, prices, 1, count, dp);
            int skip = solve(i+1, prices, 0, count, dp);
            return dp[i][buy][count] = max(take, skip);
        }
        //sell state
        if(buy==1){
            int sell = prices[i] + solve(i+1, prices, 0, count-1, dp);
            int hold = solve(i+1, prices, 1, count, dp);
            return dp[i][buy][count] =  max(sell, hold);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0, prices, 0, 2, dp);
    }
};