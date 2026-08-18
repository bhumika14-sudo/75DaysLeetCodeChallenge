class Solution {
public:
    // int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
    //     int n = word1.size();
    //     int m = word2.size();
    //     if(i==n) return m-j;
    //     if(j==m) return n-i;

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     if(word1[i] == word2[j]){
    //         return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
    //     }
    //     else{
    //         int ins = 1 + solve(word1, word2, i, j+1, dp);
    //         int replace = 1 + solve(word1, word2, i+1, j+1, dp);
    //         int dlt = 1 + solve(word1, word2, i+1, j, dp);

    //         return dp[i][j] = min({ins, replace, dlt});
    //     }

    // }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(word1, word2, 0, 0, dp);

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // dp[n] = m-j;
        // dp[m] = n-i;
        for(int j=0; j<=m; j++){
            dp[n][j] = m-j;
        }
        for(int i=0; i<=n; i++){
            dp[i][m] = n-i;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int insert = 1 + dp[i][j+1];
                    int dlt = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];

                    dp[i][j] = min({insert, dlt, replace});
                }
            }
        }
        return dp[0][0];
    }
};