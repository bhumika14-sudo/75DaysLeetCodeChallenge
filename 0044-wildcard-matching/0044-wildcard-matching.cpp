class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();

        if(i == n && j == m) return true;
        if(j==m) return false; // pattern khtm 
        if(i == n){   // string khtm 
            while(j < m){
                if(p[j] != '*'){
                    return false;
                }
                j++;
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i]==p[j] || p[j] == '?'){
            return dp[i][j] = solve(i+1, j+1, s, p, dp);
        }

        if(p[j] == '*'){
            int takeStar = solve(i, j+1, s, p, dp);
            int notTakeStar = solve(i+1, j, s, p, dp);
            return dp[i][j] = takeStar || notTakeStar;
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, p, dp);
        
    }
};