class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> mp;
        for(char ch : t){
            mp[ch]++;
        }
        int left = 0;
        int right = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIdx = -1;

        while(right < n){
            if(mp[s[right]] > 0){
                cnt++;
            }
            mp[s[right]]--;
            while(cnt == t.size()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sIdx = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};