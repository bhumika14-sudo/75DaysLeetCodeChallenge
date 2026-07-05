class Solution {
public:
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }

    bool isPredecessor(string &a, string &b){
        if(b.size() != a.size() + 1)
            return false;
        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i == a.size();
    }

    // int solve(int i, int prev, vector<string>& words, vector<vector<int>>& dp){
    //     int n = words.size();

    //     if(i == n)
    //         return 0;

    //     if(dp[i][prev + 1] != -1)
    //         return dp[i][prev + 1];

    //     int notTake = solve(i + 1, prev, words, dp);
    //     int take = 0;
    //     if(prev == -1 || isPredecessor(words[prev], words[i])){
    //         take = 1 + solve(i + 1, i, words, dp);
    //     }
    //     return dp[i][prev + 1] = max(take, notTake);
    // }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int notTake = dp[i+1][prev+1];
                int take = 0;
                if(prev==-1 || isPredecessor(words[prev],words[i])){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take,notTake);
            }
        }
        return dp[0][0];
        
        // return solve(0, -1, words, dp);
    }
};