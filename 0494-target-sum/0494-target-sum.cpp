class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        //Impossible cases 
        if(totalSum + target < 0 || (totalSum + target)%2 != 0){
            return 0;
        }

        int k = (totalSum + target)/2;
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        //Base Case
        if(nums[0]==0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
            if(nums[0] <= k){
                dp[0][nums[0]]=1;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                int notTake = dp[i-1][j];
                int take=0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take + notTake; 
            }
        }
        return dp[n-1][k];
    }
};