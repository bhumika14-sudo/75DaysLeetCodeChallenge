class Solution {
public:
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }

    bool check(string &small, string &large){
        if(small.size()+1 != large.size()) return false;
    
        int i=0, j=0;
        while(j < large.size()){
            if(i < small.size() && small[i] == large[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==small.size(); 
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();

        vector<int> dp(n,1);
        int ans = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[j], words[i]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
            ans= max(ans, dp[i]);
        }
        return ans;
    }
};