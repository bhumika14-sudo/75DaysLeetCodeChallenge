class Solution {
public:
    int solve(string& s, int i, vector<int>& dp){
        int n = s.size();
        if(i==n) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int way1 = solve(s, i+1, dp); //treat every number as singal.
        int way2 = 0; // treat numbers as 2;
        if(i+1 < n){
            int number = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(number >= 10 && number <= 26){
                way2 = solve(s, i+2, dp);
            }
        }
        return dp[i] = way1 + way2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, 0, dp);
    }
};