class Solution {
public:
    string solve(string s){
        string ans = "";
        int i=0;

        while(i < s.size()){
            int count = 0;
            char digit = s[i];

            while(i < s.size() && s[i] == digit){
                count++;
                i++;
            }
            ans += to_string(count);
            ans += digit;
        }    
        return ans;

    }
    string countAndSay(int n) {
        string curr = "1";
        for(int i=1; i<n; i++){
            curr = solve(curr);
        }
        return curr;
    }
};