class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {

            while(i < j && !isVowel(s[i]))
                i++;

            while(i < j && !isVowel(s[j]))
                j--;

            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }
};


// class Solution {
// public:
//     string reverseVowels(string s) {
//         int n = s.size();

//         vector<char> vowels;

//         // Saare vowels store karo
//         for(int i = 0; i < n; i++) {
//             if(s[i] == 'a' || s[i] == 'A' ||
//                s[i] == 'e' || s[i] == 'E' ||
//                s[i] == 'i' || s[i] == 'I' ||
//                s[i] == 'o' || s[i] == 'O' ||
//                s[i] == 'u' || s[i] == 'U') {
                
//                 vowels.push_back(s[i]);
//             }
//         }

//         // Vowels ka order reverse
//         reverse(vowels.begin(), vowels.end());

//         // Original string mein replace
//         int j = 0;

//         for(int i = 0; i < n; i++) {
//             if(s[i] == 'a' || s[i] == 'A' ||
//                s[i] == 'e' || s[i] == 'E' ||
//                s[i] == 'i' || s[i] == 'I' ||
//                s[i] == 'o' || s[i] == 'O' ||
//                s[i] == 'u' || s[i] == 'U') {

//                 s[i] = vowels[j];
//                 j++;
//             }
//         }

//         return s;
//     }
// };