class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();

        vector<char> vowels;

        // Saare vowels store karo
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'A' ||
               s[i] == 'e' || s[i] == 'E' ||
               s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' ||
               s[i] == 'u' || s[i] == 'U') {
                
                vowels.push_back(s[i]);
            }
        }

        // Vowels ka order reverse
        reverse(vowels.begin(), vowels.end());

        // Original string mein replace
        int j = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'A' ||
               s[i] == 'e' || s[i] == 'E' ||
               s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' ||
               s[i] == 'u' || s[i] == 'U') {

                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};