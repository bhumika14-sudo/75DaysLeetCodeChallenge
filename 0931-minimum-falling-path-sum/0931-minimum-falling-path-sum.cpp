class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n;  j++){
                int down = dp[i-1][j];
                int leftDia = (j-1 >= 0) ? dp[i-1][j-1] : INT_MAX;
                int rightDia = (j+1 < n) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({down, leftDia, rightDia});
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans , dp[n-1][j]);
        }
        return ans;
    }
};