class Solution {
public:
    bool vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        int ans = 0;

        while(right < n){
            if(vowel(s[right])){
                cnt++;
            }
            if(right - left + 1 > k){
                if(vowel(s[left])){
                    cnt--;
                }
                left++;
            }
            right++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};