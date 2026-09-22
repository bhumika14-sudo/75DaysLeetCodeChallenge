class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        int ans = 0;
        int left = 0, right = 0;

        while(right < n) {
            if(s[right] == 'a' || s[right] == 'e' ||
               s[right] == 'i' || s[right] == 'o' ||
               s[right] == 'u') {
                count++;
            }

            right++;
            if(right - left == k) {
                ans = max(ans, count);

                if(s[left] == 'a' || s[left] == 'e' ||
                   s[left] == 'i' || s[left] == 'o' ||
                   s[left] == 'u') {
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};