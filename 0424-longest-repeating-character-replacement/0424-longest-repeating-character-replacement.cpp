class Solution {
public:
    int characterReplacement(string s, int k) {

        //unordered_map<char,int> mp;
        vector<int> mp(26, 0);
        int right = 0;
        int left=0;
        int maxLen=0;
        int maxFreq=0;

        for(right=0 ; right<s.size() ; right++){
            mp[s[right] - 'A']++; //mp[s[right]]++;

            maxFreq = max(maxFreq , mp[s[right] - 'A']);
            //maxFreq = max(maxFreq , mp[s[right]]);

            while((right-left+1) - maxFreq > k){
                mp[s[left] - 'A']--;
               // mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen , right-left+1);
        }

        return maxLen;

    }
};

//both the approachi is good but vector > map 